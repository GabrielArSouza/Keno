/**
 * @file kenomanager.h
 * @authors Gabriel Araújo de Souza e Mayra Dantas de Azevedo
 * @date 23 Abr 2017
 * @brief Arquivo contendo as definições da classe KenoManager.
 */

#ifndef _KENOMANAGER_H_
#define _KENOMANAGER_H_

/*! Includes */
#include "kenobet.h"

namespace Keno{

    class KenoManager{

        KenoBet bet;

        //<! Membros
        private:
            cash_type m_wage;      //<! Valor de cada aposta
            cash_type m_won;       //<! Dinheiro com o cliente
            set_of_bets m_numbers; //<! Vetor com os números da aposta
            int m_rounds;          //<! Quantidade de rodadas
            int m_current_round;   //<! Rodada Atual
            cash_type m_payout;    //<! Pagamento da rodada
            cash_type m_pmoney;    //<! Dinheiro recebido por rodada


        //<! Métodos
        public: 
            /**
             * @brief      Construtor
             */
            KenoManager() :m_wage(0), m_won(0), m_numbers(20), m_rounds(10), m_current_round(0)  {}

            /**
             * @brief      Inicializa o jogo: ler o arquivo do jogador, salva o valor da aposta, a quantidade
             *             de rodadas e os números apostados pelo jogador.  
             * @param[in]  filename  Nome do arquivo enviado pelo jogador contendo a aposta.
             * @return     O struct Result contendo se as operações forma realizadas com sucesso e caso tenha
             *             ocorrido um erro, uma mensagem descrevendo o erro que ocorreu.
             */
            Game::Result initialize (std::string filename);

            /*! Recupera o valor de cada aposta.*/
            /**
             * @brief      Recupera o valor de cada aposta.
             * @return     Valor da aposta.
             */
            cash_type get_wage () const;

            /**
             * @brief      Configura o valor de cada aposta.
             * @param[in]  value  valor da aposta
             */
            void set_wage (cash_type value);

            /**
             * @brief      Recupera o número de rodadas.
             * @return     Número de rodadas
             */
            int get_rounds () const;

            /**
             * @brief      Configura o número de rodadas.
             * @param[in]  value  Quantidade de rodadas.
             */
            void set_rounds ( int value);
            
            /**
             * @brief      Imprime na tela as informações do jogo.
             */
            void welcome() const;

            /**
             * @brief      Processa as rodadas, espera o jogador da a informação
             *             de que deseja proceguir.
             */
            void process() const;

            /**
             * @brief      Atualiza todos os dados de cada rodada, sorteia os números,
             *             atualiza o dinheiro do jogador, atualiza as rodadas jogadas,
             *             os números sorteados e a quantidade de acerto e o dinheiro ganho
             *             na rodada.
             */
            void update();

            /**
             * @brief      Imprime na tela os resultados da jogada.
             */
            void render();

            /**
             * @brief      Recupera a rodada atual.
             * @return     rodada atual
             */
            int get_Current_round () const;

            /**
             * @brief      Salva a rodada attual
             */
            void set_Current_round ( );

            /**
             * @brief      Sorteia 20 números
             * @return     20 números sorteados aleatoriamente
             */
            set_of_bets draw_number ();

            /**
             * @brief      Recupera o dinheiro do jogador.
             * @return     Dinheiro do jogador.
             */
            cash_type get_won () const;

            /**
             * @brief      Atualiza o dinheiro do cliente.
             * @param[in]  value  Dinheiro ganho na rodada.
             */
            void set_won ( cash_type value );

            /**
             * @brief      Recupera o pagamento da rodada.
             * @return     Pagamento da rodada.
             */
            cash_type get_payout () const;

            /**
             * @brief      Configura o pagamento da rodada
             * @param[in]  value  Quantidade de acertos na rodada
             */
            void set_payout ( int value );

            /**
             * @brief      Recupera o dinheiro pago na rodada.
             * @return     dinheiro pago na rodada.
             */
            cash_type get_pmoney () const;

            /**
             * @brief      Configura o dinheiro ganho na rodada.
             */
            void set_pmoney (  );

            /**
             * @brief      Apresenta o fim de jogo.
             */
            void end_game();

    };
}
#endif