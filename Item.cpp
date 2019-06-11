/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Item
 ********************************/
#include "Item.hpp"
Item::Item(){
    
}

std::string Item::getName(){
    return name;
}
std::string Item::getType(){
    return type;
}
std::string Item::getDescription(){
    return description;
}
int Item::getsellPrice(){
    return baseSellPrice;
}
