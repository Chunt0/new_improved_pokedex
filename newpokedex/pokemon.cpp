#include "pokemon.h"

// Constructor
Pokemon::Pokemon(){
    m_dex_num = 0;
    m_name = "";
    m_type = "";
    m_moves[0] = "";
    m_moves[1] = "";
    m_moves[2] = "";
    m_moves[3] = "";
}

// Setters

/********************************************************************
 * Function: setName
 * Description: Sets pokemon objects name.
 * Parameters: Takes a string, presummably the pokemon name.
 * Pre-Conditions: Pokemon object must exist.
 * Post-Conditions: Pokemon object now has a name assigned.
 *******************************************************************/
void Pokemon::setName(std::string name){m_name = name;}

/********************************************************************
 * Function: setDexNum
 * Description: Sets pokemon objects pokedex number.
 * Parameters: Takes an int, presummably the pokemon pokedex number.
 * Pre-Conditions: Pokemon object must exist.
 * Post-Conditions: Pokemon object now has a pokedex number assigned.
 *******************************************************************/
void Pokemon::setDexNum(int dex_num){m_dex_num = dex_num;}

/********************************************************************
 * Function: setType
 * Description: Sets pokemon objects pokemon type.
 * Parameters: Takes astring, presummably the pokemon type.
 * Pre-Conditions: Pokemon object must exist.
 * Post-Conditions: Pokemon object now has a type assigned.
 *******************************************************************/
void Pokemon::setType(std::string type){m_type = type;}

/********************************************************************
 * Function: setMoves
 * Description: Sets pokemon objects moves.
 * Parameters: Takes a fixed string* of length 4, presummably containing the pokemon's moves.
 * Pre-Conditions: Pokemon object must exist.
 * Post-Conditions: Pokemon object now has moves assigned.
 *******************************************************************/
void Pokemon::setMoves(std::string moves[4]){
    m_moves[0] = moves[0];
    m_moves[1] = moves[1];
    m_moves[2] = moves[2];
    m_moves[3] = moves[3];
}

// Getters

/********************************************************************
 * Function: getName
 * Description: Returns a type string, the pokemons name.
 * Parameters: None.
 * Pre-Conditions: Pokemon object must exist
 * Post-Conditions: A string is returned that is the pokemon's name.
 *******************************************************************/
std::string Pokemon::getName(){return m_name;}

/********************************************************************
 * Function: getType
 * Description: Returns a type string, the pokemons type.
 * Parameters: None.
 * Pre-Conditions: Pokemon object must exist
 * Post-Conditions: A string is returned that is the pokemon's type.
 *******************************************************************/
std::string Pokemon::getType(){return m_type;}

/********************************************************************
 * Function: getDexNum
 * Description: Returns a type int, the pokemons pokedex number.
 * Parameters: None.
 * Pre-Conditions: Pokemon object must exist
 * Post-Conditions: An int is returned that is the pokemon's pokedex number.
 *******************************************************************/
int Pokemon::getDexNum(){return m_dex_num;}

/********************************************************************
 * Function: getMoves
 * Description: Returns a type string*, the pokemons move list.
 * Parameters: None.
 * Pre-Conditions: Pokemon object must exist
 * Post-Conditions: A string* is returned that is the pokemon's move list. length of 4.
 *******************************************************************/
std::string* Pokemon::getMoves(){return m_moves;}

/********************************************************************
 * Function: printPokemonInfor
 * Description: Prints the pokemons variables to terminal.
 * Parameters: None.
 * Pre-Conditions: Pokemon object must exist.
 * Post-Conditions: Prints all of the pokemons private variables to std::cout.
 *******************************************************************/
void Pokemon::printPokemonInfo(){
    std::cout << "\nDex Number: " << m_dex_num << '\t'
    << "Name: " << m_name << '\t' 
    << "Type: " << m_type << '\n'
    << "Move 1: " << m_moves[0] << '\t'
    << "Move 2: " << m_moves[1] << '\t'
    << "Move 3: " << m_moves[2] << '\t'
    << "Move 4: " << m_moves[3] << '\n';

}