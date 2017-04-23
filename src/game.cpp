 #include "../include/game.h"
 
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
