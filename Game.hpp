/********************************
*Name: Sanjo Abraham
*Date: 05/31/19
*Description: Header file for Menu/Game functions
********************************/

#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include "Space.hpp"




class Game{
  private:
    
    int row;
    int col;
    int playerRow;
    int playerCol;
    int rounds;
    std::string captainName;
    Space *** space1;

    std::string playerName;
    int playerShields;
    int playerAttack;
    int playerMorale;
    int playerDefense;
    
  public:
    
    Game();
    ~Game();
    
    void Initialize();
    
    void Intro();
    
    int MainMenu();
    
    void movePlayer();
    
    bool tryMove(int);
    
    void setBoard();
    
    void doAction();
    
    void showBoard();
    
    void showKey();
    
    void showStats();
    
    void divider(int);
    
    bool isInteger(std::string);
    
//    bool isPositive(int);
    
    int intValidation(int, int);
    
    float floatValidation(float, float);

};
#endif
