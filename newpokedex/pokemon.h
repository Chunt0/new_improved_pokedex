#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <fstream>
#include <string>

class Pokemon{
private:
    // Member data types
    int m_dex_num {};
    std::string m_name {};
    std::string m_type {};
    std::string m_moves[4] {};

public:
    //Constructors/Destructors
    Pokemon(); // Default

    //Setters
    void setName(std::string);
    void setDexNum(int);
    void setType(std::string);
    void setMoves(std::string*);
    
    //Getters
    std::string getName();
    std::string getType();
    int getDexNum();
    std::string* getMoves();
    void printPokemonInfo();
};

#endif