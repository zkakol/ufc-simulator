/**
*@author Zachary Kakol
*@date 9/13/18
*@email zskakol@gmail.com
*/

#include <iostream>
#include "../include/Logger.h"

using namespace std;

int main(){
    include::Logger logger;
    logger.notice("This is a test message");
    logger.error("This is an error message");
    return 0;
}