/**
 * @file game.cpp
 * @authors Gabriel Araújo de Souza e Mayra Dantas de Azevedo
 * @date 23 Abr 2017
 * @brief Arquivo com as impletações dos métodos do namespace Game.
 */

 #include "game.h"
 
 bool Game::validate ( std::string filename){
    std::string line = " ";
    std::ifstream file (filename);
    if (file.is_open()){
        int n = 0;
        while ( getline (file, line) ){
            if(n > 2 ) return false;
            n++;
        }

        if( n < 3) return false;
        file.close();
        
    }

    return true;
        
}

bool compare(const void * a, const void * b){
    int * x = (int *) a;
    int * y = (int *) b;

    return (*x <= *y);
}
