/********************************
 *Name: Sanjo Abraham
 *Date: 05/31/19
 *Description: Implementation file of slow read.
 ********************************/
#include "slowRead.hpp"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::string;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

/**********************
 Member function that takes in a string to put out to the console. will read each character as fast as indicated by millis
 Source: https://nodehead.com/c-how-to-console-typewriter-effect/
 **********************/
void SlowRead::readSlow(const string message, int millis){
    int x = 0;
    while(message[x] != '\0'){
        cout << message[x] << flush;
        sleep_for(milliseconds(millis));
        x++;
    }
}
