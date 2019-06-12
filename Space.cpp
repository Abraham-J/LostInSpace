/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of Space class, and abstract class.
 ********************************/
#include "Space.hpp"
#include <string>
#include <iostream>

using std::string;

Space::Space(){
    
}
/********************************
 Set the map after each change in sapce type
 ********************************/
void Space::setMap(Space * m_up, Space * m_down, Space * m_left, Space * m_right){
    up = m_up;
    down = m_down;
    left = m_left;
    right = m_right;
}
/********************************
getter functions for type and character
 ********************************/
string Space::getType(){
    return type;
}
string Space::getCharacter(){
    return character;
}
/********************************
getter functions that return a space pointer (polymorphism)
 ********************************/
Space * Space::getUp(){
    return up;
}
Space * Space::getDown(){
    return down;
}
Space * Space::getLeft(){
    return left;
}
Space * Space::getRight(){
    return right;
}
