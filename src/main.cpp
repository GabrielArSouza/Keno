#include <iostream>
#include "../include/kenomanager.h"

int main ( int argc, char* argv[]) {

	if(not Game::validate( argv[1]) ){
		std::cout << " Arquivo inválido! Por favor, tente novamente\n";
		return 1;
	}

	Keno::KenoManager game;

	int turns = game.get_rounds();
	while( turns > 0){

		game.set_rounds(--turns);
	}


	return EXIT_SUCCESS;
}
