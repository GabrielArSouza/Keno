#ifndef _KENOBET_H_
#define _KENOBET_H_

    #include <iostream>
    #include "game.h"

namespace Keno{

    class KenoManager{

        //<! Membros
        private:
            cash_type m_wage;    //<!Valor de cada aposta
            set_of_bets m_spots; //<! Vetor com os números da aposta
            int m_rounds;


        //<! Métodos
        public: 
            /*! Construtor. */
            KenoManager() :m_cash(0) { /*empty*/ }

            /*! Inicializa o jogo.*/
            void initialize (char[] argv);

            /*! Recupera o valor de cada aposra.*/
            cash_type get_wage () const;

            /*! Configura o valor de cada aposta.*/
            void set_wage (cash_type value);

            /*! Recupera o número de rodadas.*/
            int get_rounds (cash_type value);

            /*! Configura o número de rodadas.*/
            void set_rounds ( int value);
            

    };
}
#endif