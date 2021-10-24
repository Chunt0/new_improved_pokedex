#ifndef POKEDEX_H
#define POKEDEX_H

#include "pokemon.h"
#include <iostream>
#include <fstream>
#include <string>

class Pokedex{
private:
    // Member data types
    std::string m_owner;
    int m_num_of_pokemon;
    Pokemon *m_dex;
    char* m_dex_path;

public:
    //Constructor/Destructors
    Pokedex(); // Default
    Pokedex(std::fstream&, char*); //input stream param constructor
    ~Pokedex(); // Destructor
    

    //Setters
    void setOwner(std::string);
    void setNum(int);
    void setDex(std::fstream&);

    //Getters
    int getNum();
    std::string getOwner();
    Pokemon getPokemon();
    void printInfo();

    //Pokedex Methods
    void signIn(std::fstream &file);
    void selectionLoop();
    void searchByDex(int&, bool&);
    void searchByName(int&, bool&);
    void countByType(int&, std::string&, bool&);
    void searchByType(Pokemon*, std::string&);
    void writeToFile(int&, std::string&);
    void selectionDex(int&, bool&);
    void selectionName(int&, bool&);
    void selectionType(int&, bool&);
    void addPokemon();
};

#endif