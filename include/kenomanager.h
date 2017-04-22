#ifndef _KENOMANAGER_H_
#define _KENOMANAGER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "kenobet.h"

namespace Keno{

    class KenoManager{

        KenoBet * bet;

        //<! Membros
        private:
            cash_type m_wage;    //<!Valor de cada aposta
            set_of_bets m_spots; //<! Vetor com os números da aposta
            int m_rounds;


        //<! Métodos
        public: 
            /*! Construtor. */
            KenoManager() :m_wage(0), m_rounds(10) { /*empty*/ }

            /*! Inicializa o jogo.*/
            void initialize (std::string filename);

            /*! Recupera o valor de cada aposta.*/
            cash_type get_wage () const;

            /*! Configura o valor de cada aposta.*/
            void set_wage (cash_type value);

            /*! Recupera o número de rodadas.*/
            int get_rounds () const;

            /*! Configura o número de rodadas.*/
            void set_rounds ( int value);
            

    };
}
#endif