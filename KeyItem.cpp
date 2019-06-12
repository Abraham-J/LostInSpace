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
getter function for name
 ********************************/
string KeyItem::getName(){
    return name;
}
/********************************
  getter function for type
  ********************************/
string KeyItem::getType(){
    return type;
}
/********************************
 getter function for repair status
 ********************************/
string KeyItem::getRepairStatus(){
    return repairStatus;
}
/********************************
 setter function for repair status
 ********************************/
void KeyItem::setRepairStatus(string m_type){
    type = m_type;
}
/********************************
 getter function for description
 ********************************/
string KeyItem::getDescription(){
    return description;
}
