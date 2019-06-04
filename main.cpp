/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: main file of the final project
 ********************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Fog.hpp"
#include "Debris.hpp"
#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    Game game;
    Space space;
    int row;
    int col;
    
    game.Initialize();
    game.Intro();
    game.MainMenu();
    

    return 0;
}
