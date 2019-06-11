/********************************
*Name: Sanjo Abraham
*Date: 05/31/19
*Description: Header file for Menu/Game functions
********************************/

#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <vector>

#include "Space.hpp"

#include "RepairableItem.hpp"
#include "NonRepairableItem.hpp"

#include "UsableItem.hpp"
#include "RegularItem.hpp"
#include "ExtractableItem.hpp"

#include "RNG.hpp"
#include "slowRead.hpp"




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
    
    int carryCapacity;
    int currentItems;
    int keyItemsLength;
    
    int debrisCount;
    int planetCount;
    int nebulaCount;
    int stationCount;
    int spacesLeft;
    
//    std::vector<RepairableItem *> AllKeyItems;//lists all the key items. will delete each one once found
    std::vector<RepairableItem *> KeyItemList;
    std::vector<NonRepairableItem *> KeyItemList2;
    
    std::vector<UsableItem *> UsableItemList;//usable item inventory
    std::vector<RegularItem *> RegularItemList;//sellable item inventory
    std::vector<ExtractableItem *> ExtractableItemList; //extractable item inventory
    
    
    RNG generator;
    
    SlowRead reader;
    
    //key items are bools so that they are only used once
    bool matterStabilized;
    bool phaserArmed;
    bool photonReady;
    bool radarActive;
    bool commLineActive;
    bool warpOnline;
    bool shieldRefined;
    
    bool foundStabilizer;
    bool foundPhaser;
    bool foundPhoton;
    bool foundRadar;
    bool foundComm;
    bool foundWarp;
    bool foundShield;
    
    bool firstPlanetFound;
    
    bool readTextSlow;
    
  public:
    
    Game();
    ~Game();
    
    void Initialize();
    
    void Intro();
    
    int MainMenu();
    
    void movePlayer();
    
    bool tryMove(int);
    
    void placeSpace(int, int, int);
    
    void setBoard();
    
    void doAction();
    
    void staffDayOff();
    
    void talk();
    
    void tradeItem();
    
    void grabItem();
    
    void useItem();
    
    void showBoard();
    
    void showKey();
    
    void showStats();
    
    void viewKeyInventory();
    
    void viewInventory();
    
    void viewDescriptions();
    
    void viewKeyDescriptions();
            
    void divider(int);
    
    bool isInteger(std::string);
    
//    bool isPositive(int);
    
    int intValidation(int, int);
    
    float floatValidation(float, float);

};
#endif
