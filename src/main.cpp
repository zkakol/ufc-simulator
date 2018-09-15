/**
*@author Zachary Kakol
*@date 9/13/18
*@email zskakol@gmail.com
*/

#include <iostream>
#include "../include/Logger.h"
#include "model/Roster.h"

using namespace std;

int main(){
    include::Logger logger;
    model::Roster r;
    r.initializeRoster();
    return 0;
}