/**
 * @file game.h
 * @authors Gabriel Araújo de Souza e Mayra Dantas de Azevedo
 * @date 23 Abr 2017
 * @brief Arquivo contendo elementos comuns a KenoBet e KenoGame.
 */

#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>   //<! std::cout, std::cin
#include <vector>     //<! std::vector, push_back(), begin(), end()
#include <algorithm>  //<! std::shuffle, std::copy, std::sort, std::unique, binary_search
#include <iterator>   //<! std::begin, std::end, std::distance
#include <fstream>    //<! is_open(), close()
#include <string>     //<! getline(), >>
#include <sstream>    //<! std::stringstream
#include <iomanip>    //<! std::setw, std::setfill
#include <random>     //<! std::random_device, std::mt19937

using number_type = unsigned short int ;         // <! Tipo de dados para os números do Keno.
using cash_type = float ;                        // <! Define o tipo do dinheiro no Keno.
using set_of_bets = std::vector < number_type >; // <! Define o tipo do vetor com números do Keno.


namespace Game{

     static const int MIN_NUMBER_SPOTS = 1;      //<! Menor número de apostas
     static const int MAX_NUMBER_SPOTS = 15;     //<! Maior número de apostas
     static const int MIN_SPOT         = 1;      //<! Menor número apostado
     static const int MAX_SPOT         = 80;     //<! Maior número apostado
     static const int MIN_ROUNDS       = 1;	     //<! Menor número de rodadas
     static const int MAX_ROUNDS       = 10;     //<! Maior número de rodadas
     static const cash_type MIN_WAGE   = 1.0;	 //<! Menor valor de aposta
     static const cash_type MAX_WAGE = 10000.0;  //<! Maior valor de aposta

    /**
     * @brief      Erro ou Sucesso e armazena mensagem de erro,
     *             caso um seja detectado.
     */
    struct Result{
        bool success;
        std::string message;
    };

    /**
     * Tabela de pagamentos do Keno.
     */
    static std::vector <cash_type> payouts[15] = 
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

    /**
     * @brief      Valida a aposta informada pelo jogador
     * @param[in]  filename  Nome do arquivo contendo a aposta
     * @return     Sim, caso o arquivo contenha as três informações necessárias,
     *             não, caso contrário
     */
    bool validate ( std::string filename);

}

#endif