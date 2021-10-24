#include "pokedex.h"
#include "pokemon.h"


/****************************************************************
 * Function: getFile
 * Description: Returns an fstream as an rvalue(i think)
 * Parameters: char * --> this should be passed as a CML argument
 * Pre-Conditions: Pokedex executable is executed
 *      with a CML argument of a path to a file.
 * Post-Conditions: A std::fstream is returned.
 ***************************************************************/
std::fstream getFile(char* path){
    std::fstream file(path);
    if(file.fail()){
        std::cerr << "Input a path to a text file as a Command Line argument\n";
        exit(1);
    }
    return file;
};

/******************************************************************
 * Function: main
 * Description: The main function driver. Creates the pokedex object and calls this objects methods.
 * Parameters: Takes int and a char**. User must input the path to the pokedex txt file in the commandline when running driver.
 * Pre-Conditions: All associated libraries and source code must be compiled together
 * Post-Conditions: Pokedex program is completed.
 *****************************************************************/
int main(int argc, char** argv){
    //Begin by pulling in an fstream file.
    std::fstream dex_file = getFile(argv[1]);
    Pokedex pokedex{dex_file, argv[1]};
    
    //Sign in. Sets all variables of Pokedex object.
    pokedex.signIn(dex_file);
    pokedex.selectionLoop();
    
    return 0;
}