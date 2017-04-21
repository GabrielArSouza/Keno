#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector> 

using number_type = unsigned short int ; // <! data type for a keno hit .
using cash_type = float ; // <! Defines the wage type in this application .
using set_of_bets = std::vector < number_type >;

namespace Keno{

        std::vector <cash_type> payouts = 
        {
            {0, 3},                                                           //<! Tabela para 1 número
            {0, 1, 9},                                                        //<! Tabela para 2 números
            {0, 1, 2 , 16},                                                   //<! Tabela para 3 números
            {0, 0.5, 2, 6 ,12},                                               //<! Tabela para 4 números
            {0, 0.5, 1, 3, 15, 50},                                           //<! Tabela para 5 números
            {0, 0.5, 1, 2, 3, 30, 75},                                        //<! Tabela para 6 números
            {0, 0.5, 0.5, 1, 6, 12, 36, 100},                                 //<! Tabela para 7 números
            {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},                              //<! Tabela para 8 números
            {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},                          //<! Tabela para 9 números
            {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},                       //<! Tabela para 10 números
            {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},                 //<! Tabela para 11 números
            {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},            //<! Tabela para 12 números
            {0, 0, 0, 0.5, 0,5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},       //<! Tabela para 13 números
            {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500}, //<! Tabela para 14 números
            {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 10000}  //<! Tabela para 15 números
        };

        
}

#endif