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

/********************************
 Setter and getter functions for the items name, repair status, type and description.
 ********************************/
string KeyItem::getName(){
    return name;
}
string KeyItem::getType(){
    return type;
}
string KeyItem::getRepairStatus(){
    return repairStatus;
}
void KeyItem::setRepairStatus(string m_type){
    type = m_type;
}
string KeyItem::getDescription(){
    return description;
}
