#ifndef _KENOBET_H_
#define _KENOBET_H_

    #include <iostream>
    #include "game.h"

    class KenoBet{

        //<! Membros
        private:
            cash_type m_cash;    //<!Dinheiro total que o jogador aposta
            set_of_bets m_spots; //<! Vetor com os números da aposta


        //<! Métodos
        public: 
            /*! Construtor. */
            KenoBet() :m_cash(0) { /*empty*/ }

            /*! Adiciona os números válidos à aposta.*/
            bool add_number (number_type value);

            /*! Recupera quantidade de números apostados. */
            std::size_t size () const;

            /*! Configura o valor da aposta.*/
            bool set_wage (cash_type value);

            /*! Recupera o valor da aposta.*/
            cash_type get_wage () const;

            /*! Verifica a interseção entre os números sorteados e os da aposta. */
            set_of_bets get_hits( const set_of_bets & hits_ ) const;

            /* Recupera o vetor com os números que o jogador apostou. */
            set_of_bets get_spots( ) const;

    };

#endif