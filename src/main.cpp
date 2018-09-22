/**
*@author Zachary Kakol
*@date 9/13/18
*@email zskakol@gmail.com
*/

#include <iostream>
#include "../include/Logger.h"
#include "model/Roster.h"
#include "model/DanaWhite.h"

using namespace std;

int main(){
    include::Logger logger;
    model::Roster r;
    r.initializeRoster();
    model::DanaWhite dana;
    dana.sayHeWasNeverMyFriend(r.getRandomFighter());
    return 0;
}