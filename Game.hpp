/********************************
*Name: Sanjo Abraham
*Date: 05/31/19
*Description: Header file for Menu/Game functions
********************************/

#ifndef GAME_HPP
#define GAME_HPP
#include <string>





class Game{
  private:
    
    int row;
    int col;

  public:
    
    Game();
    ~Game();
    
    void Initialize();
    
    void Intro();
    
    int MainMenu();
    
    void divider();

    bool isInteger(std::string);
    
//    bool isPositive(int);
    
    int intValidation(int, int);
    
    float floatValidation(float, float);

};
#endif
