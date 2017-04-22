#include "../include/kenobet.h"

 /*! Adiciona os números válidos à aposta.*/
bool KenoBet::add_number (number_type value){

    return true;
}

/*! Recupera quantidade de números apostados. */
std::size_t KenoBet::size () const{
    return sizeof(m_spots);
}

/*! Configura o valor da aposta.*/
bool KenoBet::set_wage (cash_type value){
    m_cash = value;
}

/*! Recupera o valor da aposta.*/
cash_type KenoBet::get_wage () const{
    return m_cash;
}

/*! Verifica a interseção entre os números sorteados e os da aposta. */
set_of_bets KenoBet::get_hits( const set_of_bets & hits_ ) const{
    return m_spots; //stub
}

/* Recupera o vetor com os números que o jogador apostou. */
set_of_bets KenoBet::get_spots( ) const{
    return m_spots;
}