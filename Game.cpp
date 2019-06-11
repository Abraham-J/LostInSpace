/********************************
*Name: Sanjo Abraham
*Date: 05/31/19
*Description: Implementation file of Menu/Game.
********************************/

#include "Game.hpp"

#include "Space.hpp"
#include "Fog.hpp"
#include "Debris.hpp"
#include "Nebula.hpp"
#include "Station.hpp"
#include "Planet.hpp"

//#include "slowRead.hpp"

#include "KeyItem.hpp"
#include "RepairableItem.hpp"
#include "NonRepairableItem.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for;
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::vector;


Game::Game(){
    rounds = 1;
    playerShields = 40;
    playerAttack = 5;
    playerMorale = 50;
    playerDefense = 3;
    carryCapacity = 15;
    currentItems = 0;
    
    planetCount = 3;
    nebulaCount = 1;
    stationCount = 1;
    
    matterStabilized = false;
    phasersArmed = false;
    photonsReady = false;
    radarActive = false;
    commLineActive = false;
    warpOnline = false;
    shieldsRefined = false;
    
    firstPlanetFound = false;
    
    readTextSlow = true;

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
    
    debrisCount = (row*col)-planetCount-nebulaCount-stationCount-1; //set debris count as the remaining spots (subtract 1 because player will start on debris)
    spacesLeft = (debrisCount + planetCount + nebulaCount + stationCount);
    
    cout << "Let's make the game a little personal, what's your name? ";
    cin >> captainName;
    cin.clear();
    cin.ignore(999,'\n');
    
    cout << "You have the option to read text at a faster rate. (TAs enter 1 if you want to speed the process of going through the game)" << endl;
    cout << "1. Yes, read faster." << endl;
    cout << "2. No, it's okay." << endl;
    int choice = Game::intValidation(1,2);
    if(choice == 1){
        readTextSlow = false;
    }

    cout << "Okay, " << playerName << " let's get started." << endl;
    Game::divider(60);
    cout << endl;
    
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

    string setting = "(...Where are we?) \n(This part of space doesn't seem familiar...) \n";
    
    string setting2 = "Voice A: Captain! Are you alright sir? \n\n";
    
    string setting3 = "Captain ";
    setting3 += captainName;
    setting3 += ": I'm fine Lieutenant. Do you have any idea what happened? \n\nLieutenant: Your guess is as good as mine. I've tried to scan the area, but it seems like several parts of our ship have taken damage. \n\n";
    
    string setting4 = "Captain ";
    setting4 += captainName;
    setting4 += ": How long before our computers can have a full report on the damage? \n\nLieutenant: Already underway. Should be available in just a minute.\n\n";
    
    if (readTextSlow == true){
        reader.readSlow(setting, 30);
        reader.readSlow(setting2,30);
        reader.readSlow(setting3, 30);
        reader.readSlow(setting4, 30);
    }
    else{
        cout << setting;
        cout << setting2;
        cout << setting3;
        cout << setting4;
    }
    
    cout << "..." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    
    string setting5 = "\nLieutenant: The damage report is in. It seems like our main weapons array, warp drive, communication systems, and scanners are either malfunctioning or completely taken off the hull of the ship\n\n";
    
    string setting6 =  "Captain ";
    setting6 += captainName;
    setting6 += ": Well is anything working right now?\n\nLieutenant: Our thrusters and life support are the only fully functioning systems at the moment.\n\n";
    
    string setting7 = "Captain ";
    setting7 += captainName;
    setting7 += ": Our options are limited, but let's make the best of what we can. Let's explore the area and see if we can scavage any missing parts\n\nLieutenant: Aye sir.\n";
    
    if (readTextSlow == true){
        reader.readSlow(setting5, 30);
        reader.readSlow(setting6,30);
        reader.readSlow(setting7, 30);
    }
    else{
        cout << setting5;
        cout << setting6;
        cout << setting7;
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}
/**************************
 *This member function finds out which function the user wants to use, or if they want to quit.
 **************************/
int Game::MainMenu(){
    Game::divider(60);
    cout << endl << "Round " << rounds << endl << endl;
    Game::showBoard();
    Game::movePlayer();
    Game::setBoard();
    Game::doAction();
    Game::showStats();
    rounds++;
    playerMorale--;
    return 1;
}

/**************************
 *Prints out the game board to the user
 **************************/
void Game::showBoard(){
    for(int i=0; i<row; i++){

        for(int j=0; j<col; j++){
            if(j==0 && i ==0 ){
                cout <<"\t\t\t";//center the board
                Game::divider((col+1)*3);
                cout << endl;
            }
            if(j==0){
                cout <<"\t\t\t";
                cout <<"!";
            }
            if(i == playerRow && j == playerCol){
                cout << " 1 ";

            }
            else{
                cout << space1[i][j]->getCharacter();

            }
            if(j == col-1){
                cout <<"!";
            }
        }
        cout  << endl;
    }
    cout <<"\t\t\t";
    Game::divider((col+1)*3);
    cout << endl;
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
        cout << "8. View Inventory" << endl;
        cout << "9. Show Charter Territory" << endl;
        int choice = Game::intValidation(1,9);
        if (choice ==8){
            Game::viewInventory();
        }
        if (choice == 7){
            Game::showStats();
        }
        if (choice == 6){
            Game::showKey();
        }
        if (choice == 9){
            Game::showBoard();
        }
        else{
            badChoice = Game::tryMove(choice);
        }
    }

}
/**************************
 *Validates that the move is possible (doesn't go off board) and will  move player using a function call. If the space you are moving to already has a different space type (other than FOG) then you just move there.
 **************************/
bool Game::tryMove(int choice){
    int randNumb;
    spacesLeft = (debrisCount + planetCount + nebulaCount + stationCount);
    if (choice == 1){
        if (space1[playerRow][playerCol]->getUp() == nullptr){
            cout << "Odd, our thrusters seem to push us back to where we started." << endl;
        }
        else if(space1[playerRow-1][playerCol]->getType() == "Fog"){ //if that spot is Fog
            randNumb = generator.intGen(1, spacesLeft);
            Game::placeSpace(playerRow-1,playerCol, randNumb);
            return true;
        }
        else{ // move to whatever it was before
            playerRow--;
            return true;
        }
    }
    if(choice ==2){
        if (space1[playerRow][playerCol]->getRight() == nullptr){
            cout << "Odd, our thrusters seem to push us back to where we started." << endl;
        }
        else if(space1[playerRow][playerCol+1]->getType() == "Fog"){ //if that spot is Fog
            randNumb = generator.intGen(1, spacesLeft);
            Game::placeSpace(playerRow,playerCol+1, randNumb);
            return true;
        }
        else{
            playerCol++;
            return true;
        }
    }
    if(choice ==3){
        if (space1[playerRow][playerCol]->getDown() == nullptr){
            cout << "Odd, our thrusters seem to push us back to where we started." << endl;
        }
        else if(space1[playerRow+1][playerCol]->getType() == "Fog"){ //if that spot is Fog
            randNumb = generator.intGen(1, spacesLeft);
            Game::placeSpace(playerRow+1,playerCol, randNumb);
            return true;
        }
        else{
            playerRow++;
            return true;
        }
    }
    if(choice ==4){
        if (space1[playerRow][playerCol]->getLeft() == nullptr){
            cout << "Odd, our thrusters seem to push us back to where we started." << endl;
        }
        else if(space1[playerRow][playerCol-1]->getType() == "Fog"){ //if that spot is Fog
            randNumb = generator.intGen(1, spacesLeft);
            Game::placeSpace(playerRow,playerCol-1, randNumb);
            return true;
        }
        else{
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
 *Called by Game function in order to see if it's possible to place a new type of space onto FOG.
 **************************/
void Game::placeSpace(int pRow, int pCol, int randSpace){
    
    if(randSpace <= stationCount && stationCount != 0){
        space1[pRow][pCol] = new Station;
        playerRow = pRow;
        playerCol = pCol;
        stationCount--;
        
        string newStation = "Lieutenant: Captain, is that a space station? Let's ask for permission to dock.\n\nCaptain ";
        newStation += playerName;
        newStation += ": Yes, hail them.\n\n";
        
        if (readTextSlow == true){
            reader.readSlow(newStation, 10);
        }
        else{
            cout << newStation;
        }

        cout << "..." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        if(firstPlanetFound == false){
            string newStation2 = "Station: Please identify yourself. We are unable to verify your origins.\n\n(We nust be further than we thought.)\n\nCaptain ";
            newStation2 += playerName;
            newStation2 += ": We are the lead exploratory star ship of the United Federation of Planets. We come from the Alpha sector. We apologize for the abrupt visit. Our ship was launched into this part of space, we believe that we may have either been attacked or warp travelled due to some malfunction. We are missing several parts of our ship, as you can see. We are clearly no threat to you. If you would allow, please let us dock and see if there are any supplies that would allow us to find our way out of here.\n\n";

            
            
            string newStation3 = "Station: Very well. We will inform the neighboring civilizations about your arrival to expedite your docking process. Please feel free to use our facilities. \n\nCpation ";
            newStation3 += playerName;
            newStation3 += ": We appreciate your hospitality. If there is anything that can be done, please let us know.\n\n";
            
            if (readTextSlow == true){
                reader.readSlow(newStation2, 10);
                reader.readSlow(newStation3,10);
            }
            else{
                cout << newStation2;
                cout << newStation3;
            }
            
            firstPlanetFound = true;
            
        }
        
        else{
            
            string newStation4 = "Station: You must be our visitor that we have been briefed about. We know of your situation. Please make yourselves at home. Docking bay 3 is available for your to dock in.\n\n";

            if (readTextSlow == true){
                reader.readSlow(newStation4, 10);
            }
            else{
                cout << newStation4;
            }
        }
        
    }
    
    else if ((randSpace <= (stationCount + nebulaCount)) && (randSpace > stationCount) && (nebulaCount != 0)){
        space1[pRow][pCol] = new Nebula;
        playerRow = pRow;
        playerCol = pCol;
        nebulaCount--;
        if(matterStabilized == false){
            string newNebula = "(Woah, I have a headahce. This area isn't stable to stay on for long. Maybe if we had a method for stabilizg out matter.)\n\n";
            
            if (readTextSlow == true){
                reader.readSlow(newNebula, 10);
            }
            else{
                cout << newNebula;
            }

        }
        else{
            string newNebula2 = "(Hmm, something seems off, but right now our ship seems fine. In fact we might be cloaked to any enemeies in the area.)\n\n";
            
            if (readTextSlow == true){
                reader.readSlow(newNebula2, 10);
            }
            else{
                cout << newNebula2;
            }

        }
    }
    
    else if ((randSpace <= (planetCount + stationCount + nebulaCount)) && (randSpace > stationCount + nebulaCount) && (planetCount!= 0) ){
        space1[pRow][pCol] = new Planet;
        playerRow = pRow;
        playerCol = pCol;
        planetCount--;
        if (firstPlanetFound == false){
            string newPlanet = "Lieutenant: Captain, incoming hail from that planet.\n\nCaptain ";
            newPlanet += playerName;
            newPlanet += ": Patch them through\n\nPlanet: State your purpose, your ship is unidentifiable to any civilizations within this sector.\n\n(How far have we travelled?)\n\nCaptain ";
            newPlanet += playerName;
            newPlanet += ": We are the lead exploratory star ship of the United Federation of Planets. We come from the Alpha sector. We apologize for the abrupt visit. Our ship was launched into this part of space, we believe that we may have either been attacked or warp travelled due to some malfunction. We are missing several parts of our ship, as you can see. We are clearly no threat to you. If you would allow, please let us dock and see if there are any supplies that would allow us to find our way out of here.\n\n";

            if (readTextSlow == true){
                reader.readSlow(newPlanet, 10);
            }
            else{
                cout << newPlanet;
            }
            
            cout << "..." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
            
            string newPlanet2 = "Planet: We verified from a recent freighter ship that ship parts were found in the area, suggesting that your theory of what happened to you may be correct. Please forgive our suspicion. We aren't used to many guests. We will inform the neighboring civilizations about your arrival to expedite your docking process. In the meantime, feel free to dock and explore the un restricted areas of our planet.\n\n";

            if (readTextSlow == true){
                reader.readSlow(newPlanet2, 10);
            }
            else{
                cout << newPlanet2;
            }
            
            firstPlanetFound = true;
        }
        else{
            string newPlanet3 = "Lieutenant: Captain, incoming hail from that planet.\n\nCaptain ";
            newPlanet3 += playerName;
            newPlanet3 += ": Patch them through.\n\n";
            
            if (readTextSlow == true){
                reader.readSlow(newPlanet3, 10);
            }
            else{
                cout << newPlanet3;
            }
            
            
            cout << "..." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
            string newPlanet4 = "Planet: You must be our visitor that we have been briefed about. We know of your situation. Please make yourselves at home. We have a small docking station for use, if you don't plan on staying long.\n\n";
            
            if (readTextSlow == true){
                reader.readSlow(newPlanet4, 10);
            }
            else{
                cout << newPlanet4;
            }
        }
    }
    
    else{
        space1[pRow][pCol] = new Debris;
        playerRow = pRow;
        playerCol = pCol;
        debrisCount--;
        string newDebris = "(Nothing but space around here. Perhaps there's something of use around here)\n";
        if (readTextSlow == true){
            reader.readSlow(newDebris, 10);
        }
        else{
            cout << newDebris;
        }
    }
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
    int choice;
    if(space1[playerRow][playerCol]->getType() == "Planet"){
        cout << "1. Talk to Colony" << endl;
        cout << "2. Trade items" << endl;
        cout << "3. Relieve staff for the day" << endl;
        choice = Game::intValidation(1,3);
        if (choice == 1){
            Game::talk();
        }
        else if (choice == 2){
            Game::tradeItem();
        }
        else{
            Game::staffDayOff();
        }
    }
    if(space1[playerRow][playerCol]->getType() == "Debris"){
        cout << "1. Scavange the area for parts" << endl;
        cout << "2. Use item" <<endl;
        choice = Game::intValidation(1,2);
        if (choice == 1){//scavange
            Game::grabItem();
        }
        else{// use item
            Game::useItem();
        }

    }
    if(space1[playerRow][playerCol]->getType() == "Station"){
        
    }
    if(space1[playerRow][playerCol]->getType() == "Nebula"){
        
    }
}

/**************************
 Called by Game function to increase morale of the ship
 **************************/
void Game::staffDayOff(){
    string DayOff = "(Wow, I didn't realize how badly we needed this. It feels good to take a day off. I'm sure this will help with motivating staff.)\n";
    if( readTextSlow == true){
        reader.readSlow(DayOff, 20);
    }
    else{
        cout << DayOff;
    }
    playerMorale += 2;
}

/**************************
 Called by Game function to trade with
 **************************/
void Game::tradeItem(){
    float multiplier;
    multiplier = generator.floatGen(.8,1.2);//multiplies by cost for buyable items
    
}

/**************************
 Called by Game function to talk to colony when on a planet
 **************************/
void Game::talk(){
    int positiveOutcome;
    positiveOutcome = generator.intGen(1,10);//1-4 is good, 5-9 is neutral, 10 is bad
}

/**************************
 Called by Game function to scavange for an item in debris
 **************************/
void Game::grabItem(){
    int randNumb;
    randNumb = generator.intGen(1, 100);
    if (randNumb <= 80){//get a regular item
        
    }
    else { //get a key item
        
    }
}
/**************************
 Called by Game function to use a found item while on debris
 **************************/
void Game::useItem(){
    
}
/**************************
 Prints out what each part of the map means
 **************************/
void Game::showKey(){
    Game::divider(32);
    cout << endl;
    cout << "!\t   Key \t\t\t !"<< endl;
    cout << "!\t 'X' FOG \t\t !" << endl;
    cout << "!\t '1' Player \t\t !" << endl;
    cout << "!\t 'O' Planet \t\t !" << endl;
    cout << "!\t 'S' Space Station \t !" << endl;
    cout << "!\t ':' Nebula \t\t !" << endl;
    cout << "!\t 'E' Enemy \t\t !" << endl;
    cout << "!\t ' ' Debris \t\t !" << endl;
    Game::divider(32);
    cout << endl;
}
/**************************
 Prints out the player's current stats
 **************************/
void Game::showStats(){
    Game::divider(32);
    cout << endl;
    cout << "!\t   Stats \t\t !"<< endl;
    cout << "!\t Shields: "<< playerShields << " \t\t !" << endl;
    cout << "!\t Morale: " <<playerMorale << " \t\t !" << endl;
    cout << "!\t Attack: " << playerAttack << " \t\t !" << endl;
    cout << "!\t Defense: " << playerDefense << " \t\t !" << endl;
    cout <<"!\t Inventory: " <<currentItems << "/" << carryCapacity << "\t !" << endl;
    Game::divider(32);
    cout << endl;
}
/**************************
 Prints out what key item inventory that the player has gathered.
 **************************/
void Game::viewKeyInventory(){
    keyItemsLength = KeyItemList2.size() + KeyItemList.size();
    for(int i = 1; i <= KeyItemList.size(); i++){
        if(KeyItemList.size() != 0){
            cout << i << ". " << KeyItemList.at(i-1)->getName() << " " << endl;
        }
    }
    int j = 0;
    for(int i = KeyItemList.size()+1; i <= keyItemsLength; i++){
        cout << i << ". " << KeyItemList2.at(j)->getName() << " " << endl;
        j++;
    }
}
/**************************
 Prints out the other items that the player has gathered
 **************************/
void Game::viewInventory(){
    
}
/**************************
 Prints out key item descriptions
 **************************/
void Game::viewKeyDescriptions(){
    Game::viewKeyInventory();
    int choice;
    cout << keyItemsLength+1 << ". Go back." << endl;
    Game::intValidation(1, keyItemsLength+1);
    if (choice <= KeyItemList.size()){//get discription for repairable items that player has acquired
        cout << KeyItemList.at(choice-1)->getDescription() << endl;
    }
    if (choice == keyItemsLength+1){ //get discription for non-repairable items that player has acquired
        
    }
    else{
        cout << KeyItemList2.at(choice-KeyItemList.size()-1)->getDescription() << endl;
    }
}
/**************************
 Prints out key item descriptions
 **************************/
void Game::viewDescriptions(){
    
}

/**************************
*The function is a style choice to divide parts of the program with several dashes. 
**************************/
void Game::divider(int amount){
	for(int j =0; j< amount; j++){
		cout <<"-";
	}
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

        //this is very specific for taking in a percentage, not just for floats
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

