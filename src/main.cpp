#include <iostream>
#include "../include/kenomanager.h"

int main ( int argc, char* argv[]) {

	if (argc != 2 ) {
      exit(EXIT_FAILURE);
   	}

	if(not Game::validate( argv[1]) ){
		std::cout << " Arquivo inválido! Por favor, tente novamente\n";
		return EXIT_FAILURE;
	}

	Keno::KenoManager game;

	Game::Result init = game.initialize( argv[1]);  //<! Guarda o resultado inicialização do jogo
	if(not init.success){
		std::cout << init.message << std::endl;

		return EXIT_FAILURE;
	}

	game.welcome();
	int turns = game.get_rounds();

	while( turns > 0){
		game.render();
		game.set_rounds(--turns);
	}


	return EXIT_SUCCESS;
}
