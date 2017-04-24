/**
 * @file main.cpp
 * @authors Gabriel Araújo de Souza e Mayra Dantas de Azevedo
 * @date 23 Abr 2017
 * @brief Arquivo principal que executa o jogo.
 */

/*! Includes */
#include "kenomanager.h"

int main ( int argc, char* argv[]) {

	/*! Verifica se o jogador informou o arquivo da aposta*/
	if (argc != 2 ) {
      exit(EXIT_FAILURE);
   	}

   	/*! Verifica se o arquivo é válido, se não for imprime mensagem de erro*/
	if(not Game::validate( argv[1]) ){
		std::cout << " Arquivo inválido! Por favor, tente novamente\n";
		return EXIT_FAILURE;
	}

	//<! Abreviação
	Keno::KenoManager game;

	//<! Guarda o resultado inicialização do jogo
	Game::Result init = game.initialize( argv[1]); 

	/*! Verifica se todos os dados da aposta são válidos, caso algum não seja, 
	 *	imprime mensagem informando qual o campo não é válido e qual a faixa
	 *	de valores aceitos.
	 */ 
	if(not init.success){
		std::cout << init.message << std::endl;

		return EXIT_FAILURE;
	}

	/*! Chama o método que dá as boas vindas */
	game.welcome();
	
	/*! Loop do jogo */
	while( game.get_rounds() > game.get_Current_round()){
		
		game.process();
		game.update();
		game.render();

	}

	/*! Método que finaliza o jogo */
	game.end_game();


	return EXIT_SUCCESS;
}
