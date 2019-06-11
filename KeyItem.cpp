/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of KeyItem class, an abstract class
 ********************************/
#include "KeyItem.hpp"
#include <string>
using std::string;

KeyItem::KeyItem(){
    
}
string KeyItem::getName(){
    return name;
}
string KeyItem::getType(){
    return type;
}
string KeyItem::getDescription(){
    return description;
}
