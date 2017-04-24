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
            cash_type m_payout; //<! Pagamento da rodada
            cash_type m_pmoney; //<! Dinheiro recebido por rodada


        //<! Métodos
        public: 
            /*! Construtor. */
            KenoManager() :m_wage(0), m_won(0), m_numbers(20), m_rounds(10), m_current_round(0)  {}

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

            /*! */
            void process() const;

            void update();

            /*! Imprime na tela os resultados da jogada. */
            void render();

            /*! Recupera a rodada atual. */
            int get_Current_round () const;

            /*! Salva a rodada atual. */
            void set_Current_round ( );

            /*! Sorteia 20 números */
            set_of_bets draw_number ();

            /*! Recupera o dinheiro do cliente.*/
            cash_type get_won () const;

            /*! Atualiza o dinheiro do cliente.*/
            void set_won ( cash_type value );

            /*! Recupera o pagamento da rodada */
            cash_type get_payout () const;

            /*! Configura o pagamento da rodada */
            void set_payout ( int value );

            /*! Recupera o dinheiro pago na rodada*/
            cash_type get_pmoney () const;

            /*! Configura o dinheiro ganho na rodada*/
            void set_pmoney (  );
    };
}
#endif