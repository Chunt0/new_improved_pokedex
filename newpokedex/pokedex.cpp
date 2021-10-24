#include "pokedex.h"

// Constructors

    // Default
Pokedex::Pokedex(){
    m_owner = "";
    m_num_of_pokemon = 1;
    m_dex = new Pokemon[m_num_of_pokemon];
    m_dex_path = nullptr;
}
   
    // Input Stream
Pokedex::Pokedex(std::fstream &file, char* path){
    m_owner = "";
    m_dex_path = path;
    file >> m_num_of_pokemon;
    m_dex = new Pokemon[m_num_of_pokemon];
}
 
    // Destructor
Pokedex::~Pokedex(){delete[] m_dex;}


// Setters

/*******************************************************************
 * Function: setOwner
 * Description: Sets class variable owner.
 * Parameters: Takes a string as input.
 * Pre-Conditions: Pokedex object must exist.
 * Post-Conditions: Pokedex object now has owner variable assigned.
 ******************************************************************/ 
void Pokedex::setOwner(std::string owner){m_owner = owner;}

/*******************************************************************
 * Function: setNum
 * Description: Sets class variable of number of pokemon in pokedex.
 * Parameters: Takes an int as input
 * Pre-Conditions: Pokedex object must exist.
 * Post-Conditions: Pokedex object now has number of pokemon in pokedex variable assigned.
 ******************************************************************/ 
void Pokedex::setNum(int num){m_num_of_pokemon = num;}

/*******************************************************************
 * Function: setDex
 * Description: Creates a class variable of type Pokemon* whose size is
 *      allocated dynamically based on the amount of pokemon in the pokedex. 
 * Pre-Conditions: Pokedex object must exist and have a number of pokemon variable set
 * Post-Conditions: Pokedex object now has an empty Pokemon* array that can be filled with
 *      pokemon objects.
 ******************************************************************/ 
void Pokedex::setDex(std::fstream &file){
        for (int i{0}; i < m_num_of_pokemon; ++i){
            int dex_num{}; file >> dex_num;

            std::string name{}; file >> name;

            std::string type{}; file >> type;
            
            std::string move[4];
            file >> move[0];
            file >> move[1];
            file >> move[2];
            file >> move[3];
            
            m_dex[i].setDexNum(dex_num);
            m_dex[i].setName(name);
            m_dex[i].setType(type);
            m_dex[i].setMoves(move);
        }
}

// Getters

/*******************************************************************
 * Function: getOwner
 * Description: Returns a string (owner of the object)
 * Parameter: None.
 * Pre-Conditions: Pokedex object must exist.
 * Post-Conditions: String is returned, string is the owners name.
 ******************************************************************/ 
std::string Pokedex::getOwner(){return m_owner;}

/*******************************************************************
 * Function: getNum
 * Description: Returns an int (amount of pokemon objects in pokedex object)
 * Parameters: None.
 * Pre-Conditions: Pokedex object must exist.
 * Post-Conditions: Int is returned, int is the amount of pokemon in the pokedex.
 ******************************************************************/ 
int Pokedex::getNum(){return m_num_of_pokemon;}

/*******************************************************************
 * Function: printInfo
 * Description: A for loop moves through the indices of the Pokemon* array. 
 *      For each pokemon object in the array, the pokemon class method to print
 *      that pokemon's information is called
 * Parameters: None.
 * Pre-Conditions: Pokedex must exist and the Pokemon* must be built using user inputed file.
 * Post-Conditions: Every Pokemon in the Pokedex is printed to the screen.
 ******************************************************************/ 
void Pokedex::printInfo(){
    for (int i{0}; i < m_num_of_pokemon; ++i){
        m_dex[i].printPokemonInfo();
    }
};

//Pokedex Methods

/******************************************************************
 * Function: signIn
 * Description: Welcomes the user and sets all of users Pokedex variables.
 * Pre-Conditions: A default pokedex or parameter defined pokedex 
 *      must be initialized.
 * Post-Conditions: No return type. Since pokedex was passed by reference
 *      we are able to set the owner variable without having made a copy. 
 ******************************************************************/
void Pokedex::signIn(std::fstream &file){
    std::string user{};
    std::cout << "******POKEDEX*******\n\nUSER: ";
    std::cin >> user;
    m_owner = user;
    setDex(file);
};

/*******************************************************************
 * Function: selectionLoop
 * Description: Main menu of the Pokedex. Allows the user to select various
 *      functions the pokedex object can perform.
 * Parameters: None.
 * Pre-Conditions: Pokedex object must exist.
 * Post-Conditions: Exits pokedex.
 ******************************************************************/ 
void Pokedex::selectionLoop(){
    bool game_on{true};
    int selection {0};
    while(game_on){
        std::cout << "\n1. Search by Dex Number.\n" << "2. Search by Name.\n" << "3. Search by Type.\n" << "4. Add a Pokemon.\n" << "5. Quit\n" << ":: ";
        std::cin >> selection;
        int i{};
        bool in_file{false};
        int count{};
        switch(selection){
            case 1:
                selectionDex(i, in_file);
                break;
               
            case 2:
                selectionName(i, in_file);
                break;
                 
            case 3:
                selectionType(count, in_file);
                break;

            case 4:
                addPokemon();
                break;

            case 5:
                std::cout << "\nCome back with more Pokemon!\n";
                game_on = false;
                break;
            default:
                std::cout << "\nPlease enter an integer 1-5\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
        }
    }
}

/*******************************************************************
 * Function: searchByDex
 * Description: Searches user's pokedex by pokedex number based on user input.
 * Parameters: An int reference to indicate which index that matches to inputed number
 *      and a boolean reference that indicates if the number entered was in the dex file.
 * Pre-Conditions: Pokedex object, int variable and bool variable must exist.
 * Post-Conditions: Variables that were passed by reference are used later in the selection loop.
 ******************************************************************/ 
void Pokedex::searchByDex(int &index, bool &in){
    int num{};
    std::cout << "\nEnter Dex Number: ";
    std::cin >> num;
    for (int i{0}; i < m_num_of_pokemon; ++i){
        if(num == m_dex[i].getDexNum()){
            in = true;
            index = i;
        }
    }
    if (!in){
        std::cout << "\nNo Pokemon with Dex Number " << num << " found. Please search again.\n";
    }
}

/*******************************************************************
 * Function: searchByName
 * Description: Searches user's pokedex by pokemon name based on user input.
 * Parameters: An int reference to indicate which index that matches to inputed name
 *      and a boolean reference that indicates if the name entered was in the dex file.
 * Pre-Conditions: Pokedex object, int variable and bool variable must exist.
 * Post-Conditions: Variables that were passed by reference are used later in the selection loop.
 ******************************************************************/ 
void Pokedex::searchByName(int &index, bool &in){
    std::string name{};
    std::cout << "\nEnter Name: ";
    std::cin >> name;
    for (int i{0}; i < m_num_of_pokemon; ++i){
        if(name == m_dex[i].getName()){
            in = true;
            index = i;
        }
    }
    if (!in){
        std::cout << "\nNo Pokemon with the name " << name << " found. Please search again.\n";
    }
}

/*******************************************************************
 * Function: countByType
 * Description: Searches user's pokedex by pokemon type based on user input.
 * Parameters: An int reference to indicate which count of how many types found that matches to inputed type
 *      a string reference that is the pokemon type, and a boolean reference that indicates if the type entered was in the dex file.
 * Pre-Conditions: Pokedex object, int variable, string variable and bool variable must exist.
 * Post-Conditions: Variables that were passed by reference are used later in the selection loop.
 ******************************************************************/ 
void Pokedex::countByType(int &count, std::string &type, bool &in){
    for (int i{0}; i < m_num_of_pokemon; ++i){
        if(type == m_dex[i].getType()){ 
            ++count;
            in = true;
        }
    }
    if (!in){
        std::cout << "\nNo Pokemon of type " << type << " was found. Please search again.\n";
    }
}

/*******************************************************************
 * Function: searchByType
 * Description: Searches user's pokedex by pokemon type based on user input and builds an array of all pokemon that match the type.
 * Parameters: A dynamically allocated Pokemon* that was created jsut before fuinction call
 *      and a string reference that is the type. 
 * Pre-Conditions: Pokemon object must have been allocated and the user inputed type must exist.
 * Post-Conditions: Variables that were passed by reference are used later in the selection loop.
 ******************************************************************/ 
void Pokedex::searchByType(Pokemon *list, std::string &type){
    int index{};
    for (int i{0}; i < m_num_of_pokemon; ++i){
        if (type == m_dex[i].getType()){
            list[index] = m_dex[i];
            ++index;    
        }
    }
}

/*******************************************************************
 * Function: writeToFile
 * Description: Creates an fstream object and then the searched pokemon is written to this file.
 * Parameters: An int reference that is the index of the pokemon being written
 *      and a string reference that is the file path.
 * Pre-Conditions: User must have selected "y" when prompted if they want to write to file.
 * Post-Conditions: The file is either written or appended with the pokemon information.
 ******************************************************************/ 
void Pokedex::writeToFile(int &index, std::string &path){
    std::fstream new_file;
    if(new_file){
    
        new_file.open(path, std::ios::app | std::ios::out);
    
        std::string *movelist;
        movelist = m_dex[index].getMoves();
    
        if (new_file.is_open()){
            new_file << m_dex[index].getDexNum() << " "
            << m_dex[index].getName() << " "
            << m_dex[index].getType() << '\n'
            << movelist[0] << " " << movelist[1] << " "
            << movelist[2] << " " << movelist[3] << std::endl;
        }
        new_file.close();
    }
    else{
        std::cout << "\nFile path error. Please try again.\n";
    }
}

/*******************************************************************
 * Function: selectionDex
 * Description: Called in the selection loop. Contains the search function searchByDex. Allows user to write to file or print the information to terminal
 * Parameters: An int reference that is the index of the searched pokemon, and a boolean reference that confirms
 *      that the pokemon is or is not in the file.
 * Pre-Conditions: The related search function must have been called and the int and bool variables contain data.
 * Post-Conditions: Prints pokemon information to terminal or writes it to file.
 ******************************************************************/ 
void Pokedex::selectionDex(int &index, bool &in){
    std::cout << "\nWould you like to write this to file? [y/n] ";
    std::string answer{"y"};
    std::cin >> answer;

    if (answer == "y"){
        std::string write_file;
        std::cout << "\nPlease enter the path to the file to write: ";
        std::cin >> write_file;
        searchByDex(index, in);
        if(in){
            writeToFile(index, write_file);
        }
    }
    else if(answer == "n"){
        searchByDex(index, in);
        if(in){
            m_dex[index].printPokemonInfo();
        }
    }
    else{
        std::cout << "\nI'll take that as a no.\n";
        searchByDex(index, in);
        if (in){
            m_dex[index].printPokemonInfo();
        }
    }
}

/*******************************************************************
 * Function: selectionName
 * Description: Called in the selection loop. Contains the search function searchByName. Allows user to write to file or print the information to terminal
 * Parameters: An int reference that is the index of the searched pokemon, and a boolean reference that confirms
 *      that the pokemon is or is not in the file.
 * Pre-Conditions: The related search function must have been called and the int and bool variables contain data.
 * Post-Conditions: Prints pokemon information to terminal or writes it to file.
 ******************************************************************/ 
void Pokedex::selectionName(int &index, bool &in){
    std::cout << "\nWould you like to write this to file? [y/n] ";
    std::string answer{"y"};
    std::cin >> answer;

    if (answer == "y"){
        std::string write_file;
        std::cout << "\nPlease enter the path to the file to write: ";
        std::cin >> write_file;
        searchByName(index, in);
        if(in){
            writeToFile(index, write_file);
        }
    }
    else if(answer == "n"){
        searchByName(index, in);
        if(in){
            m_dex[index].printPokemonInfo();
        }
    }
    else{
        std::cout << "\nI'll take that as a no.\n";
        searchByName(index, in);
        if (in){
            m_dex[index].printPokemonInfo();
        }
    }   
}

/*******************************************************************
 * Function: selectionDex
 * Description: Called in the selection loop. Contains the search function searchByType. Allows user to write to file or print the information to terminal
 * Parameters: An int reference that is the counti of the searched pokemon, and a boolean reference that confirms
 *      that the pokemon is or is not in the file.
 * Pre-Conditions: The related search function must have been called and the int and bool variables contain data.
 * Post-Conditions: Prints pokemon information to terminal or writes it to file.
 ******************************************************************/ 
void Pokedex::selectionType(int &count, bool &in){
    std::cout << "\nWould you like to write this to file? [y/n] ";
    std::string answer;
    std::cin >> answer;

    if (answer == "y"){
        ;//writeToFile
    }
    else if (answer == "n"){
        std::string type;
        std::cout << "\nEnter type: ";
        std::cin >> type;
        countByType(count, type, in);
        if (in){
            Pokemon *type_list = new Pokemon[count];
            searchByType(type_list, type);
            for(int i{0}; i < count; ++i){
                type_list[i].printPokemonInfo();
            }
            delete[] type_list;
        }
    }
    else{
        std::cout << "\nI'll take that as a no.\n";
        std::string type;
        std::cout << "\nEnter type: ";
        std::cin >> type;
        countByType(count, type, in);
        if (in){
            Pokemon *type_list = new Pokemon[count];
            searchByType(type_list, type);
            for(int i{0}; i < count; ++i){
                type_list[i].printPokemonInfo();
            }
        delete[] type_list;
        }
    }
}

/*******************************************************************
 * Function: addPokemon
 * Description: Allows user to add a new pokemon to their file.
 * Parameters: None
 * Pre-Conditions: Pokedex and file path to the pokedex file must exist.
 * Post-Conditions: The user inputed pokemon information is added to the pokedex and the pokedex is updated with this new information.
 ******************************************************************/ 
void Pokedex::addPokemon(){
    std::cout << "So you caught a new pokemon, huh?\nLet's add it to the DEX!\n";
    Pokemon new_pokemon;
    int dex_num{0};
    std::cout << "Dex Number: ";
    std::cin >> dex_num;
    new_pokemon.setDexNum(dex_num);
    std::string name;
    std::cout << "Name: ";
    std::cin >> name;
    new_pokemon.setName(name);
    std::string type;
    std::cout << "Type: ";
    std::cin >> type;
    new_pokemon.setType(type);
    std::string moves[4];
    std::cout << "Moves: ";
    std::cin >> moves[0] >> moves[1] >> moves[2] >> moves[3];
    new_pokemon.setMoves(moves);

    std::ifstream infile;
    std::ofstream outfile;
    std::fstream file;

    infile.open(m_dex_path);
    outfile.open(m_dex_path, std::ios::app);
    if (infile.is_open()){
        outfile << '\n' << new_pokemon.getDexNum() << " "
        << new_pokemon.getName() << " " 
        << new_pokemon.getType() << '\n'
        << moves[0] << " " << moves[1] << " " << moves[2] << " " << moves[3];
        std::cout << "\nPokemon has been appended to your Pokedex.\n";
    }

    m_num_of_pokemon = m_num_of_pokemon + 1;
    std::string updated_size{std::to_string(m_num_of_pokemon)};
    file.open(m_dex_path);
    if (file.is_open()){
        file << updated_size;
    }
    file.close();

    Pokemon *temp_dex = new Pokemon[m_num_of_pokemon];
    for (int i{0}; i < m_num_of_pokemon-1; i++){
        temp_dex[i] = m_dex[i];
    }
    temp_dex[m_num_of_pokemon-1] = new_pokemon;
    delete[] m_dex;
    m_dex = temp_dex;
}