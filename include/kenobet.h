#ifndef _KENOBET_H_
#define _KENOBET_H_

    /*! Includes */
    #include "game.h"

    class KenoBet{

        //<! Membros
        private:
            cash_type m_cash;    //<! Dinheiro total que o jogador aposta
            set_of_bets m_spots; //<! Vetor com os números da aposta


        //<! Métodos
        public: 
            
            /**
             * @brief      Construtor.
             */
            KenoBet() :m_cash(0) { }
           
            /**
             * @brief      Adiciona os números válidos à aposta.
             * @param[in]  value  Número que se deseja adicionar.
             * @return     Sim, se o número atender os critérios para ser adicionado,
             *             não, caso contrário.
             */
            bool add_number (number_type value);

            /**
             * @brief      Recupera a quantidade de números apostados.
             * @return     retorna quantos números válidos foram apostados.
             */
            std::size_t size () const;
            
            /**
             * @brief      Configura o valor da aposta.
             * @param[in]  value  Valor da aposta informada pelo usuário
             * @return     Sim, se a aposta tiver um valor válido e for inserida,
             *             não, caso contrário.
             */
            bool set_wage (cash_type value);

            /**
             * @brief      Recupera o valor da aposta.
             * @return     O valor da aposta.
             */
            cash_type get_wage () const;

            /**
             * @brief      Verifica a interseção entre os números sorteados e os da aposta.
             * @param[in]  hits_  Números sorteados.
             * @return     Vetor com os números acertados.
             */
            set_of_bets get_hits( const set_of_bets & hits_ ) const;

            
            /**
             * @brief      Recupera o vetor com os números que o jogador apostou.
             * @return     Vetor com os números apostados pelo jogador.
             */
            set_of_bets get_spots( ) const;

    };

#endif