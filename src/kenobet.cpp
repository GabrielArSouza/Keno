/**
 * @file kenobet.cpp
 * @authors Gabriel Araújo de Souza e Mayra Dantas de Azevedo
 * @date 23 Abr 2017
 * @brief Arquivo com as impletações dos métodos da classe KenoBet.
 */


/*! Includes */
#include "kenobet.h"
#include "game.h"
#include "graal.h"

bool compare(const void * a, const void * b){
	int * x = (int *) a;
	int * y = (int *) b;

	return (*x <= *y);
}


/*! Adiciona os números válidos à aposta.*/
bool KenoBet::add_number (number_type value){

	if ( value >= Game::MIN_SPOT && value <= Game::MAX_SPOT )
	{
		m_spots.push_back(value);
        graal::quick_sort( &m_spots[0], &m_spots.back(), compare , sizeof(value));
        auto end = std::unique(m_spots.begin(), m_spots.end());
        int sz = std::distance ( m_spots.begin(), end);
        m_spots.resize(sz);
		return true;
	}
	else
		return false;
}

/*! Recupera quantidade de números apostados. */
std::size_t KenoBet::size () const{
    return m_spots.size();
}

/*! Configura o valor da aposta.*/
bool KenoBet::set_wage (cash_type value){
   
    if ( value < Game::MIN_WAGE || value > Game::MAX_WAGE ) return false;
    else m_cash = value;

    return true;
}

/*! Recupera o valor da aposta.*/
cash_type KenoBet::get_wage () const{
    return m_cash;
}

/*! Verifica a interseção entre os números sorteados e os da aposta. */
set_of_bets KenoBet::get_hits( const set_of_bets & hits_ ) const{
    
    auto tm = size();
    set_of_bets hits;

	for (auto i(0ul); i < tm; i++ )
	{
		auto target = m_spots[i];
		auto resp = binary_search( hits_.begin(), hits_.end(), target);
		if ( resp ) 
			hits.push_back(target);
	}

	return hits;	
}

/*! Recupera o vetor com os números que o jogador apostou. */
set_of_bets KenoBet::get_spots( ) const{
    return m_spots;
}

