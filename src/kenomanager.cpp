#include "../include/kenomanager.h"
#include "../include/kenobet.h"

Game::Result Keno::KenoManager::initialize ( std::string filename){
	//<! abrir arquivo
	std::string line;
	std::ifstream file (filename);
	file.is_open();

	//<! pega aposta
	getline( file, line );
	cash_type wage;
	std::stringstream(line) >> wage;
	Game::Result response;
	
	//<! valida aposta
	if (bet.set_wage(wage)){
		response.success = true;
	}
	else{
		response.success = false;
		response.message = " A aposta não é um valor válido, por favor, aposte entre R$ 1,00 - 10.000,00 ";
	}

	if ( response.success )
	{
		//<! Pega número de rodadas
		getline( file, line );
		int rounds;
		std::stringstream(line) >> rounds;

        this->set_rounds(rounds);
        this->set_wage( wage / rounds );

		//<! Valida rodadas
		if ( rounds < Game::MIN_ROUNDS || rounds > Game::MAX_ROUNDS )
		{
			response.success = false;
			response.message = " O número de rodadas não é válido, por favor, aposte entre 1 - 10 rodadas ";
		}else {
			response.success = true;
		}
	}

	if ( response.success )
	{
		//<! Pega números apostados
		getline( file, line );
		int cont = 0;
		std::stringstream stream(line);
		
		while ( true )
		{
			number_type bets;
			stream >> bets;
			if (!stream) break;
			auto t = bet.add_number(bets);
			if ( t ) cont++;

		}

		//<! Valida quantidade de números
		if ( cont >= Game::MIN_NUMBER_SPOTS && cont <= Game::MAX_NUMBER_SPOTS )
		{
            
			response.success = true;
		}else
		{
			response.success = false;
			response.message = " O número de números apostados é inválido, por favor, aposte ente 1 - 15 números ";
        }

        
	}

	this->set_won(bet.get_wage());

    return response;
}

/*! Recupera o valor de cada aposra.*/
cash_type Keno::KenoManager::get_wage () const{
    return m_wage;
}

/*! Configura o valor de cada aposta.*/
void Keno::KenoManager::set_wage (cash_type value){
    m_wage = value;
}

/*! Recupera o número de rodadas.*/
int Keno::KenoManager::get_rounds () const{
    return m_rounds;
}

/*! Configura o número de rodadas.*/
void Keno::KenoManager::set_rounds ( int value ){
    m_rounds = value;
}

/*! Recupera a rodada atual. */
int Keno::KenoManager::get_Current_round () const {
	return m_current_round;
}

/*! Salva a rodada atual. */
void Keno::KenoManager::set_Current_round ( int value ) {
	m_current_round = value;
}

/*! Recupera o dinheiro do cliente.*/
cash_type Keno::KenoManager::get_won () const{
    return m_won;
}

/*! Atualiza o dinheiro do cliente.*/
void Keno::KenoManager::set_won ( cash_type value ){
    m_won += value;
}

/*! Sorteia 20 números */
set_of_bets Keno::KenoManager::draw_number () {
          
    //<! Cria vetor temporários com números de 1 a 80
    number_type *temp = new number_type[80];
    for(auto i(0); i < 80; i++)
        *(temp+i) = i+1;

    //<! Seed e shuffles dos elementos do vetor temporário
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(temp, temp+80, g);

    // <! Copia os vinte primeiros elementos do vetor temporário
    std::copy(temp, temp+20, m_numbers.begin());
    delete [] temp; //<! Desaloca vetor temporário

    //<! Ordena o vetor 
    std::sort(m_numbers.begin(), m_numbers.end());
    return m_numbers;
}

/*! Ver números acertados */
set_of_bets Keno::KenoManager::hits( set_of_bets draw, set_of_bets bet ){
	auto tm = bet.size();
	set_of_bets hits;

	for (auto i(0ul); i < tm; i++ )
	{
		auto target = bet[i];
		auto resp = binary_search( draw.begin(), draw.end(), target);
		if ( resp ) 
			hits.push_back(target);
	}

	return hits;	
}

/*! Imprime menssagem de boas vindas */
 void Keno::KenoManager::welcome() const{
    int turns = bet.size();

    auto table_len(23);
    int double_table_len = table_len/2;

    std::cout << ">>> Aposta lida com sucesso!";
    std::cout << std::left << std::setw(5)<<"\n" << "Você vai apostar um total de R$" 
            << bet.get_wage() <<" reais." << std::setw(5)<<"\n"

            << "Serão " << m_rounds << " rodadas, cada uma valendo R$" << m_wage << ".\n" << std::setw(5) << "\n"
            << "Sua aposta possui " <<  turns << " números: [";
    for( auto i(0); i < turns; ++i)
        std::cout << bet.get_spots()[i] << " ";
    std::cout << "].\n";

    std::cout << ""  << std::setw(4) << "" << "Aqui está a tabela com os valores dos acertos :\n";
 
    std::cout << " " << std::setw(3) << " " << std::setw(double_table_len -1) << std::setfill( '-' ) << ""
              << "+" << std::setw(double_table_len) << "" << "\n";
    std::cout << " " << std::setw(3) << std::setfill(' ')<< " "<< "|" << std::setw(9) << " Acertos"
              << "|" << std::setw(double_table_len -1) << " Pagamento" << "" << "|\n";
    std::cout << " " << std::setw(3) << " " << std::setw(double_table_len -1) << std::setfill( '-' ) << ""
              << "+" << std::setw(double_table_len) << "" << "\n";

    for( auto i(0ul) ; i < Game::payouts[turns-1].size() ; ++i )
    {
        std::cout << "" << std::setw(5) << std::setfill(' ') << std::right;
        std::cout << "|"
                  << std::setw(double_table_len -2) 
                  << i
                  << "|"
                  << std::setw(double_table_len -1)
                  << Game::payouts[turns-1][i]
                  << "|\n";
    }

     std::cout << "" << std::setw(4) << "" << std::setw(double_table_len -1) << std::setfill( '-' ) << ""
              << "+" << std::setw(double_table_len) << "" << "\n";

     std::cout << std::setfill( ' ' ) << "" << std::setw(5) << "" 
              << "Bom jogo!\n";
    
    std::cout << "" << std::setw(4) << std::setfill(' ')<< "" << std::setw(table_len) << std::setfill('-') << "\n";
  
}

void Keno::KenoManager::render(){

	std::cout << ">>> Aperte ENTER para continuar. ";
	std::string enter;
	getline( std::cin, enter );

	cash_type att = -m_wage; 
	this->set_won(att);

    std::cout << std::setw(50) << std::setfill( '-' ) << "" << std::endl;
    std::cout << " Esta é a rodada #" << m_current_round 
    		  << " de #" << m_rounds << ", e sua aposta é de " 
    		  << "R$" <<  m_wage << ". Boa Sorte!\n";

    draw_number(); 
   	std::cout << " Os números sorteados são: [ ";
    for ( auto i(0); i < 20; i++)
    	std::cout << m_numbers[i] << " ";
    std::cout << "]\n";

    int t = bet.size();
    std::cout << " Os números que você apostou foram: [ ";
    for( auto i(0); i < t; ++i)
        std::cout << bet.get_spots()[i] << " ";
    std::cout << "].\n";

    std::cout << "\n";
    std::cout << "\n";

    std::cout << " Você acertou o(s) seguinte(s) número(s) [ ";
    auto hits_ = hits( m_numbers, bet.get_spots() );
    auto th = (int) hits_.size();

    for (auto i(0); i < th; ++i)
    	std::cout << hits_[i] << " ";
    std::cout << "], um total de " << th
    		  << " acerto(s) de " << t << std::endl;

    auto pg = Game::payouts[t-1][th];
    auto cash_ = m_wage*pg;

    std::cout << " A taxa de pagamento é " << pg 
    		  << ", assim você saiu com: R$" << cash_ << "\n";

   	this->set_won(cash_);
   	std::cout << " Seu saldo líquido até agora é: " << get_won() << " reais \n\n";
}