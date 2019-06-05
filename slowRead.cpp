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

void SlowRead::readSlow(const string message, int millis){
    int x = 0;
    while(message[x] != '\0'){
        cout << message[x] << flush;
        sleep_for(milliseconds(millis));
        x++;
    }
}
