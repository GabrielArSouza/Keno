/**
 * @file kenomanager.cpp
 * @authors Gabriel Araújo de Souza e Mayra Dantas de Azevedo
 * @date 23 Abr 2017
 * @brief Arquivo com as impletações dos métodos da classe KenoManager.
 */

/*!Includes*/
#include "kenomanager.h"
#include "kenobet.h"

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
	file.close();

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
void Keno::KenoManager::set_Current_round ( ) {
	m_current_round++;
}

/*! Recupera o dinheiro do cliente.*/
cash_type Keno::KenoManager::get_won () const{
    return m_won;
}

/*! Atualiza o dinheiro do cliente.*/
void Keno::KenoManager::set_won ( cash_type value ){
    m_won += value;
}

/*! Recupera o pagamento da rodada */
cash_type Keno::KenoManager::get_payout () const {
	return m_payout;
}

/*! Configura o pagamento da rodada */
void Keno::KenoManager::set_payout ( int value ){

	auto pg = Game::payouts[bet.size()][value];
	m_payout = pg;
}

/*! Recupera o dinheiro pago na rodada*/
cash_type Keno::KenoManager::get_pmoney () const {
	return m_pmoney;
}

/*! Configura o dinheiro ganho na rodada*/
void Keno::KenoManager::set_pmoney (  ){
	m_pmoney = m_payout * m_wage;
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

/**
 * @brief      Processa as rodadas, espera o jogador da a informação
 *             de que deseja proceguir.
 */
void Keno::KenoManager::process() const{

	std::cout << ">>> Aperte ENTER para continuar. ";
	std::string enter;
	getline( std::cin, enter );

}

/**
 * @brief      Atualiza todos os dados de cada rodada, sorteia os números,
 *             atualiza o dinheiro do jogador, atualiza as rodadas jogadas,
 *             os números sorteados e a quantidade de acerto e o dinheiro ganho
 *             na rodada.
 */
void Keno::KenoManager::update(){

	this->set_Current_round();

	cash_type att = -m_wage; 
	this->set_won(att);

	draw_number();

	auto hits = bet.get_hits(m_numbers);
	auto n_hits = hits.size();
	
	this->set_payout(n_hits);	
	this->set_pmoney();
    this->set_won(get_pmoney());

}

//<! Imprime na tela os resultados da jogada.
void Keno::KenoManager::render(){

	std::cout << std::setw(50) << std::setfill( '-' ) << "" << std::endl;
    std::cout << " Esta é a rodada #" << m_current_round 
    		  << " de #" << m_rounds << ", e sua aposta é de " 
    		  << "R$" <<  m_wage << ". Boa Sorte!\n";

    std::cout << " Os números sorteados são: [ ";
    for ( auto i(0); i < 20; i++)
    	std::cout << m_numbers[i] << " ";
    std::cout << "]\n";

    int t = bet.size();
    std::cout << " Os números que você apostou foram: [ ";
    for( auto i(0); i < t; ++i)
        std::cout << bet.get_spots()[i] << " ";
    std::cout << "].\n";

    std::cout << "\n\n";
   
    std::cout << " Você acertou o(s) seguinte(s) número(s) [ ";
    auto hits_ = bet.get_hits( m_numbers );
    auto th = (int) hits_.size();

    for (auto i(0); i < th; ++i)
    	std::cout << hits_[i] << " ";
    std::cout << "], um total de " << th
    		  << " acerto(s) de " << t << std::endl;

    std::cout << " A taxa de pagamento é " << this->get_payout() 
    		  << ", assim você saiu com: R$" << this->get_pmoney() << "\n";

   	std::cout << " Seu saldo líquido até agora é: " << this->get_won() << " reais \n\n";
}

/*! Apresenta o fim de jogo */
void Keno::KenoManager::end_game(){

	std::cout << ">>> FIM DE JOGO \n";
	std::cout << std::setfill('-') << std::setw(50);
	std::cout << "\n\n";

	auto gain = this->get_won() - bet.get_wage();

	std::cout << "===== SUMÁRIO =====\n\n";
	std::cout << ">>> Você entrou no jogo com um total de R$" << bet.get_wage() << " reais\n";
	if ( gain > 0 ) 
		std::cout << ">>> Você ganhou R$" << gain << " reais. Até a próxima! ;-)\n";
	else 
		std::cout << ">>> Você perdeu R$" << gain * -1 << " reais. Até a próxima! ;-)\n";
	std::cout << ">>> Você está saindo do Keno com R$" << this->get_won() << " reais.\n\n";
}