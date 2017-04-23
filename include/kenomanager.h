#ifndef _KENOMANAGER_H_
#define _KENOMANAGER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
#include "kenobet.h"

namespace Keno{

    class KenoManager{

        KenoBet bet;

        //<! Membros
        private:
            cash_type m_wage;    //<!Valor de cada aposta
            set_of_bets m_numbers; //<! Vetor com os números da aposta
            int m_rounds;


        //<! Métodos
        public: 
            /*! Construtor. */
            KenoManager() :m_wage(0), m_numbers(20), m_rounds(10){ 
                
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

             }

            /*! Inicializa o jogo.*/
            Game::Result initialize (std::string filename);

            /*! Recupera o valor de cada aposta.*/
            cash_type get_wage () const;

            /*! Configura o valor de cada aposta.*/
            void set_wage (cash_type value);

            /*! Recupera o número de rodadas.*/
            int get_rounds () const;

            /*! Configura o número de rodadas.*/
            void set_rounds ( int value);
            
            /*! Imprime na tela as informações do jogo. */
            void welcome( ) const;

            /*! Imprime na tela os resultados da jogada. */
            void render();
    };
}
#endif