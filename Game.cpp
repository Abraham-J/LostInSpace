/********************************
*Name: Sanjo Abraham
*Date: 05/31/19
*Description: Implementation file of Menu/Game.
********************************/

#include "Game.hpp"
#include "Space.hpp"
#include "Fog.hpp"
#include "Debris.hpp"
#include <string>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;



Game::Game(){

}
Game::~Game(){//Free the allocated memory and reset the values of certain variables

}
/**************************
 *This member function gets the rows and columns of the game board from the user
 **************************/
void Game::Initialize(){
    cout << "Before we start, let me get some information about the game board you'll be playing on..." << endl;
    cout << "Tell me the number of rows you'd like. Keep in mind, the larger the board, the longer the game." << endl;
    row = Game::intValidation(3,10);
    playerRow = rand()%(row);
    cout << playerRow << endl;
    cout << "Tell me the number of columns you'd like. Keep in mind, the larger the board, the longer the game." << endl;
    col = Game::intValidation(3,10);
    playerCol = rand()%(col);
    cout << playerCol << endl;
    
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
    
}
/**************************
 *This member function finds out which function the user wants to use, or if they want to quit.
 **************************/
int Game::MainMenu(){
    Game::showBoard();
    cout << endl;
    Game::movePlayer();
    Game::setBoard();

    Game::doAction();

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
        int choice = Game::intValidation(1,6);
        if (choice == 6){
            Game::showKey();
        }
        else{
            badChoice = Game::tryMove(choice);
        }
    }

}

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

void Game::showKey(){
    Game::divider(30);
    cout << "!\t   Key \t !"<< endl;
    cout << "!\t * FOG \t !" << endl;
    cout << "!\t 1 Player \t !" << endl;
    cout << "!\t O Planet \t !" << endl;
    cout << "!\t S Space Station \t !" << endl;
    cout << "!\t : Nebula \t !" << endl;
    cout << "!\t  Debris \t !" << endl;
    Game::divider(30);
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

