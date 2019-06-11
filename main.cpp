/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: main file of the final project
 ********************************/
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "Space.hpp"
#include "Fog.hpp"
#include "Debris.hpp"
#include "Game.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main(){

    
    
    srand(time(NULL));
    Game game;
    Space space;
    int row;
    int col;

    game.Initialize();
//    game.Intro(); //REMEMBER TO ADD THIS BACK AT THE END. TOOK OFF FOR TESTING PURPOSES
    bool endOfGame = false;
    while(!endOfGame){
        game.MainMenu();

    }


    return 0;
}
