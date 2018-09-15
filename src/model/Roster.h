/**
*@author Zachary Kakol
*@date 9/15/18
*@email zskakol@gmail.com
*/

#ifndef UFC_SIMULATOR_ROSTER_H
#define UFC_SIMULATOR_ROSTER_H

#include <string>
#include <fstream>
#include "../../include/Logger.h"

inline bool isInteger(std::string);

const std::string CSV_FILE_NAME = "../data/ufc3-roster.csv";

namespace model{
    class Roster{
    private:

    public:
        void initializeRoster(){
            std::ifstream file(CSV_FILE_NAME);
            std::string line = "";
            include::Logger logger;
            while(getline(file, line)){
                logger.notice(line);
            }
        }
    };
}

inline bool isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

    char * p ;
    std::strtol(s.c_str(), &p, 10) ;

    return (*p == 0) ;
}


#endif //UFC_SIMULATOR_ROSTER_H
