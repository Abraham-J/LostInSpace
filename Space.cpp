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
void Space::setArray(int m_row, int m_col){
    row = m_row;
    col = m_col;
    strArray = new string*[row];
    for(int i=0; i < row; i++){
        strArray[i] = new string[col];
    }
}
string Space::getType(){
    return type;
}
string Space::getCharacter(){
    return character;
}

void Space::DoActivity(int choice){
    
}
