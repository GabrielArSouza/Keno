#include "../include/kenomanager.h"
#include "../include/kenobet.h"

void Keno::KenoManager::initialize (char argv[]){

}

/*! Recupera o valor de cada aposra.*/
cash_type Keno::KenoManager::get_wage () const{
    return m_wage;
}

/*! Configura o valor de cada aposta.*/
void Keno::KenoManager::set_wage (cash_type value){
    m_wage = value;
}

/*! Recupera o número de rodadas.*/
int Keno::KenoManager::get_rounds () const{
    return m_rounds;
}

/*! Configura o número de rodadas.*/
void Keno::KenoManager::set_rounds ( int value){
    m_rounds = value;
}