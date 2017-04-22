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
void Keno::KenoManager::set_rounds ( int value){
    m_rounds = value;
}

void Keno::KenoManager::welcome() const{

    int turns = bet.size();

    std::cout << ">>> Aposta lida com sucesso!";
    std::cout << std::left << std::setw(5)<<"\n" << "Você vai apostar um total de " 
            << bet.get_wage() <<" reais." << std::setw(5)<<"\n"

            << "Serão " << m_rounds << " rodadas, cada uma valendo " << m_wage << ".\n" << std::setw(5) << "\n"
            << "Sua aposta possui " <<  turns << " números. São eles [";
    for( auto i(0); i < turns; ++i)
        std::cout << bet.get_spots()[i] << " ";

    std::cout << "].\n";
 
    std::cout << " " << std::setw(3) << " " << std::setw(11) << std::setfill( '-' ) << ""
              << "+" << std::setw(10) << "" << "\n";
    std::cout << " " << std::setw(3) << std::setfill(' ')<< " "<< "|" << std::setw(9) << " Acertos"
              << "|" << std::setw(10) << " Pagamento" << "" << "|\n";
    std::cout << " " << std::setw(3) << " " << std::setw(11) << std::setfill( '-' ) << ""
              << "+" << std::setw(10) << "" << "\n";

               double d1(1.0);
    for( auto i(0ul) ; i < Game::payouts[turns-1].size() ; ++i )
    {
        std::cout << "" << std::setw(5) << std::setfill(' ') << std::right;
        std::cout << "|"
                  << std::setw(9) 
                  << i
                  << "|"
                  << std::setw(10)
                  << Game::payouts[turns-1][i]
                  << "|\n";
    }

}

void Keno::KenoManager::render(){
    std::cout << "teste";
}