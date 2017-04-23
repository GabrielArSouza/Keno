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
            cash_type m_won;      //<! Dinheiro com o cliente
            set_of_bets m_numbers; //<! Vetor com os números da aposta
            int m_rounds; //<! Quantidade de rodadas
            int m_current_round; //<! Rodada Atual


        //<! Métodos
        public: 
            /*! Construtor. */
            KenoManager() :m_wage(0), m_won(0), m_numbers(20), m_rounds(10)  {}

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
            void welcome() const;

            /*! Imprime na tela os resultados da jogada. */
            void render();

            /*! Recupera a rodada atual. */
            int get_Current_round () const;

            /*! Salva a rodada atual. */
            void set_Current_round ( int value );

            /*! Sorteia 20 números */
            set_of_bets draw_number ();

            /*! Ver números acertados */
            set_of_bets hits( set_of_bets draw, set_of_bets bet );

            /*! Recupera o dinheiro do cliente.*/
            cash_type get_won () const;

            /*! Atualiza o dinheiro do cliente.*/
            void set_won ( cash_type value );
    };
}
#endif