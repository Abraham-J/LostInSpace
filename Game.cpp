/********************************
*Name: Sanjo Abraham
*Date: 05/31/19
*Description: Implementation file of Menu/Game.
********************************/

#include "Game.hpp"
#include "Space.hpp"
#include "Fog.hpp"
#include "Debris.hpp"
#include "slowRead.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for;



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;




Game::Game(){
    rounds = 1;
    playerShields = 30;
    playerAttack = 5;
    playerMorale = 100;
    playerDefense = 3;
}
Game::~Game(){//Free the allocated memory and reset the values of certain variables
    for (int i=0; i<row; i++)
        delete [] space1[i];
    delete [] space1;
}
/**************************
 *This member function gets the rows and columns of the game board from the user. After getting this information,
 it randomly places the player on the board, and will set the board up.
 **************************/
void Game::Initialize(){
    cout << "Before we start, let me get some information about the game board you'll be playing on..." << endl;
    cout << "Tell me the number of rows you'd like. Keep in mind, the larger the board, the longer the game." << endl;
    row = Game::intValidation(3,10);
    playerRow = rand()%(row);
    cout << "Tell me the number of columns you'd like. Keep in mind, the larger the board, the longer the game." << endl;
    col = Game::intValidation(3,10);
    playerCol = rand()%(col);
    
    cout << "Let's make the game a little personal, what's your name? ";
    cin >> captainName;
    cin.clear();
    cin.ignore(999,'\n');
    cout << "Okay, " << playerName << " let's get started." << endl;
    Game::divider(60);
    
    space1 = new Space**[row];
    for (int i=0; i<row; i++)
        space1[i] = new Space*[col];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            space1[i][j]= new Fog;
        }
    }
    space1[playerRow][playerCol] = new Debris;
    Game::setBoard();
}
/**************************
 *This member function sets the pace of the game and give background information to the player
 **************************/
void Game::Intro(){
    
    SlowRead reader;
    string setting = "(...Where are we?) \n(This part of space doesn't seem familiar...) \n";
    reader.readSlow(setting, 30);
    
    string setting2 = "Voice A: Captain! Are you alright sir? \n\n";
    reader.readSlow(setting2,30);
    
    string setting3 = "Captain ";
    setting3 += captainName;
    setting3 += ": I'm fine Lieutenant. Do you have any idea what happened? \n\nLieutenant: Your guess is as good as mine. I've tried to scan the area, but it seems like several parts of our ship have taken damage. \n\n";
    reader.readSlow(setting3, 30);
    
    string setting4 = "Captain ";
    setting4 += captainName;
    setting4 += ": How long before our computers can have a full report on the damage? \n\nLieutenant: Already underway. Should be available in just a minute.\n\n";
    reader.readSlow(setting4, 30);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    string setting5 = "Lieutenant: The damage report is in. It seems like our main weapons array, warp drive, communication systems, and scanners are either malfunctioning or completely taken off the hull of the ship\n\n";
    reader.readSlow(setting5, 30);
    
    string setting6 =  "Captain ";
    setting6 += captainName;
    setting6 += ": Well is anything working right now?\n\nLieutenant: Our thrusters and life support are the only fully functioning systems at the moment.\n\n";
    reader.readSlow(setting6,30);
    
    string setting7 = "Captain ";
    setting7 += captainName;
    setting7 += ": Our options are limited, but let's make the best of what we can. Let's explore the area and see if we can scavage any missing parts\n\nLieutenant: Aye sir.\n";
    reader.readSlow(setting7,30);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}
/**************************
 *This member function finds out which function the user wants to use, or if they want to quit.
 **************************/
int Game::MainMenu(){
    Game::divider(60);
    cout << "Round " << rounds << endl;
    Game::showBoard();
    cout << endl;
    Game::movePlayer();
    Game::setBoard();
    Game::doAction();
    Game::showStats();
    rounds++;
    
    return 1;
}

/**************************
 *Prints out the game board to the user
 **************************/
void Game::showBoard(){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i == playerRow && j == playerCol){
                cout << " 1 ";
            }
            else{
                cout << space1[i][j]->getCharacter();

            }
        }
        cout  << endl;
    }
}
/**************************
 *Prints out list directions player can move, validates that that's a viable move. And moves player on board. Doing so will reveal what the new space is.
 **************************/
void Game::movePlayer(){
    bool badChoice = false;
    while (badChoice == false){
        cout << "1. Move Up" << endl;
        cout << "2. Move Right" << endl;
        cout << "3. Move Down" << endl;
        cout << "4. Move Left" << endl;
        cout << "5. Don't move" << endl;
        cout << "6. Show Key" << endl;
        cout << "7. Show Stats" << endl;
        int choice = Game::intValidation(1,7);
        if (choice == 7){
            Game::showStats();
        }
        if (choice == 6){
            Game::showKey();
        }
        else{
            badChoice = Game::tryMove(choice);
        }
    }

}
/**************************
 *Validates that the move is possible (doesn't go off board) and will  move player
 **************************/
bool Game::tryMove(int choice){
    if (choice == 1){
        if (space1[playerRow][playerCol]->getUp() == nullptr){
            cout << "Nope son" << endl;
        }
        else{
            space1[playerRow-1][playerCol] = new Debris;
            playerRow--;
            return true;
        }
    }
    if(choice ==2){
        if (space1[playerRow][playerCol]->getRight() == nullptr){
            cout << "Nope son" << endl;
        }
        else{
            space1[playerRow][playerCol+1] = new Debris;
            playerCol++;
            return true;
        }
    }
    if(choice ==3){
        if (space1[playerRow][playerCol]->getDown() == nullptr){
            cout << "Nope son" << endl;
        }
        else{
            space1[playerRow+1][playerCol] = new Debris;
            playerRow++;
            return true;
        }
    }
    if(choice ==4){
        if (space1[playerRow][playerCol]->getLeft() == nullptr){
            cout << "Nope son" << endl;
            
        }
        else{
            space1[playerRow][playerCol-1] = new Debris;
            playerCol--;
            return true;
        }
    }
    if(choice == 5){
        return true;
    }
    return false;
}

/**************************
This memeber function checks if the user's choice is a valid move, if it is. it will move the player.
 **************************/
void Game::setBoard(){
    
    for(int i=0; i <row; i++){
        for(int j=0; j<col; j++){
            if(i == 0 && j == 0){
                space1[i][j]->setMap(nullptr, space1[i+1][j], nullptr, space1[i][j+1]);
//                head->up = nullptr;
//                head->left = nullptr;
//                head->right = space1[i][j+1];
//                head->down = space1[i+1][j];
            }
            else if (i == 0 && (j != 0 && j !=col-1)){
                space1[i][j]->setMap(nullptr, space1[i+1][j], space1[i][j-1], space1[i][j+1]);
//                head->up = nullptr;
//                head->left = space1[i][j-1];
//                head->right = space1[i][j+1];
//                head->down = space1[i+1][j];
            }
            else if (i == 0 && j == col-1){
                space1[i][j]->setMap(nullptr, space1[i+1][j], space1[i][j-1], nullptr);
//                head->up = nullptr;
//                head->left = space1[i][j-1];
//                head->right = nullptr;
//                head->down = space1[i+1][j];
            }
            else if ((i !=0 && i != row-1) && j == 0){
                space1[i][j]->setMap(space1[i-1][j], space1[i+1][j], nullptr, space1[i][j+1]);
//                head->up = space1[i-1][j];
//                head->left = nullptr;
//                head->right = space1[i][j+1];
//                head->down = space1[i+1][j];
            }
            else if (i == row -1 && j ==0){
               space1[i][j]->setMap(space1[i-1][j], nullptr, nullptr, space1[i][j+1]);
//                head->up = space1[i-1][j];
//                head->left = nullptr;
//                head->right = space1[i][j+1];
//                head->down = nullptr;
            }
            else if (i ==row -1 &&(j !=0 && j != col-1)){
               space1[i][j]->setMap(space1[i-1][j], nullptr, space1[i][j-1], space1[i][j+1]);
//                head->up = space1[i-1][j];
//                head->left = space1[i][j-1];
//                head->right = space1[i][j+1];
//                head->down = nullptr;
            }
            else if (i == row-1 && j == col-1){
                space1[i][j]->setMap(space1[i-1][j], nullptr, space1[i][j-1], nullptr);
//                head->up = space1[i-1][j];
//                head->left = space1[i][j-1];
//                head->right = nullptr;
//                head->down = nullptr;
            }
            else if ((i!= 0 && i!= row-1) && j == col-1){
                space1[i][j]->setMap(space1[i-1][j], space1[i+1][j], space1[i][j-1], nullptr);
//                head->up = space1[i-1][j];
//                head->left = space1[i][j-1];
//                head->right = nullptr;
//                head->down = space1[i+1][j];
            }
            else{
                space1[i][j]->setMap(space1[i-1][j], space1[i+1][j], space1[i][j-1], space1[i][j+1]);
//                head->up = space1[i-1][j];
//                head->left = space1[i][j-1];
//                head->right = space1[i][j+1];
//                head->down = space1[i+1][j];
            }
        }
    }
}
/**************************
 Prints out list of actions available at current place on board, and performs
 said action
 **************************/
void Game::doAction(){
    
}
/**************************
 Prints out what each part of the map means
 **************************/
void Game::showKey(){
    Game::divider(32);
    cout << "!\t   Key \t\t\t !"<< endl;
    cout << "!\t 'X' FOG \t\t !" << endl;
    cout << "!\t '1' Player \t\t !" << endl;
    cout << "!\t 'O' Planet \t\t !" << endl;
    cout << "!\t 'S' Space Station \t !" << endl;
    cout << "!\t ':' Nebula \t\t !" << endl;
    cout << "!\t 'E' Enemy \t\t !" << endl;
    cout << "!\t ' ' Debris \t\t !" << endl;
    Game::divider(32);
}
void Game::showStats(){
    Game::divider(32);
    cout << "!\t   Stats \t\t !"<< endl;
    cout << "!\t Shields: "<< playerShields << " \t\t !" << endl;
    cout << "!\t Morale: " <<playerMorale << " \t\t !" << endl;
    cout << "!\t Attack: " << playerAttack << " \t\t !" << endl;
    cout << "!\t Defense: " << playerDefense << " \t\t !" << endl;
    Game::divider(32);
}
/**************************
*The function is a style choice to divide parts of the program with several dashes. 
**************************/
void Game::divider(int amount){
	for(int j =0; j< amount; j++){
		cout <<"-";
	}
	cout << endl;	
}

/**************************
*The next four functions were used in order to do proper input validation.
*First, "isInteger()" will scan through a string and check to make sure
*that each character is a digit. It will then return true or false. Based on this,
*inputValidation() will either set a variable equal to the integer value of the string,
*or will prompt the user until they provide an integer.
*"isPositive" is another function that checks to make sure that the integer that was entered 
*by the user is positive.
 Lastly, there is a function that checks to see if a value is a float. It does so by only allowing integers with one decimal point.
**************************/
bool Game::isInteger(string s) {
    bool integerCheck = true;
    if(s == ""){
        integerCheck = false;
    }
    if (integerCheck== true){
        for (int i = 0; i <s.length(); i++){
            
            if(isdigit(s[i]) ==false){
                if(s[0] == '-'){
                    integerCheck = true;
                }

                else{
                    cout<< "That wasn't one of the options, please try again (non integer provided)." << endl;
                    integerCheck = false;
                    i = s.length();
                }
                
            }

        }
    }
    
    return integerCheck;
}

//bool Game::isPositive(int integer){
//  bool positiveCheck = true;
//  if(integer <= 0){
//        cout<< "That wasn't one of the options, please try again (non positive integer provided)." << endl;
//        cout<< ">>";
//        positiveCheck = false;
//    }
//    return positiveCheck;
//
//}

int Game::intValidation(int min, int max){
    bool inputCheck = false;
    string strInput;
    int intInput;
    cout << ">>";
    getline(cin, strInput);
    while (inputCheck == false){
        if(Game::isInteger(strInput) == true ){
            intInput = stoi(strInput);
            inputCheck = true;
            if(intInput < min || intInput > max){
                cout << "Please enter a number between [" << min << ", " << max << "]" << endl;
                inputCheck = false;
                cin.clear();
                cin.ignore(999,'\n');
                cout << ">>";
                getline(cin, strInput);
                
            }
        }
        else if (Game::isInteger(strInput) == false){
            inputCheck = false;
            cout << "That was an invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(999,'\n');
            cout << ">>";
            getline(cin, strInput);
            
            
        }
    }
    return intInput;
}

float Game::floatValidation(float min, float max){
    string strInput;
    string noPercent;
    
    float floatInput;
    
    bool isFloat = false;
    bool hasDecimal = false;
    bool hasPercent = false;
    
    int decimalCounter = 0;
    int strLength;
    
    cout << ">>";
    getline(cin, strInput);
    strLength = strInput.size();
    
    if (strInput[strLength-1] == '%'){
        noPercent = strInput.substr(0,strLength-1);
        strInput.clear();
        strInput = noPercent;
        hasPercent = true;
    }
    
    while(isFloat == false){
        for (int i =0; i<strInput.size(); i++){
            if(isdigit(strInput[i])){
                isFloat = true;
            }
            else if ( strInput[i] == '.' && decimalCounter < 2){
                decimalCounter++;
                isFloat = true;
                hasDecimal = true;
            }
            else{
                isFloat = false;
                i = strInput.size();
                cin.clear();
                cin.ignore(999, '\n');

            }
        }
        if(strInput != ""){
            floatInput  = stod(strInput);
            if(hasPercent == true){
                floatInput /= 100;
            }
        }
        else{
            isFloat = false;
        }

        
        if(((floatInput < min || floatInput > max) && (hasPercent == true || hasDecimal == true)) || ((floatInput < min || floatInput > max*100) && (hasPercent == false*100 && hasDecimal == false)) || isFloat == false){
            cout << "Please enter a number that is either between 1 and 99, as one of the following inputs: [" << min << ", " << max << "] or [" << min*100 << ", " << max*100 << "] or [" << min << "%, " << max << "%]" <<endl;
            cout<< ">>";
            cin.clear();
            cin.ignore(999, '\n');
            getline(cin, strInput);
            strLength = strInput.size();
            hasPercent = false;
            hasDecimal = false;
            isFloat = false;
            if (strInput[strLength-1] == '%'){
                noPercent = strInput.substr(0,strLength-1);
                strInput.clear();
                strInput = noPercent;
                hasPercent = true;
            }
        }

    }
    return floatInput;
}

