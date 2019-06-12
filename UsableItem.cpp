/*******************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of UsableItem class
 ********************************/
#include "UsableItem.hpp"

UsableItem::UsableItem(){
    
}
/*******************************
returns the integer values of the usable items cost and boost value
 ********************************/
int UsableItem::getCost(){
    return baseCost;
}
int UsableItem::getBoost(){
    return boostVal;
}
