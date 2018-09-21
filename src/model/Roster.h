/**
*@author Zachary Kakol
*@date 9/15/18
*@email zskakol@gmail.com
*/

#ifndef UFC_SIMULATOR_ROSTER_H
#define UFC_SIMULATOR_ROSTER_H

#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "../../include/Logger.h"
#include "Fighter.h"

inline bool isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

    char * p ;
    std::strtol(s.c_str(), &p, 10) ;

    return (*p == 0) ;
}

#ifdef __unix__
const std::string CSV_FILE_NAME = "../data/ufc3-roster.csv";
#elif defined(_WIN32) || defined(WIN_32)
const std::string CSV_FILE_NAME = "C:\\Users\\Zack\\ClionProjects\\ufc-simulator\\data\\ufc3-roster.csv";
const int NAME = 0;
const int STRIKING = 1;
const int GRAPPLING = 2;
const int STAMINA = 3;
const int HEALTH = 4;
const int OVERALL = 5;
#endif

namespace model{
    class Roster{
    private:

    public:
        void initializeRoster(){
            //Read each line form the CSV file
            std::ifstream file(CSV_FILE_NAME);
            std::string line = "";
            include::Logger logger;
            std::string weightClass;
            char delimiter = ',';

            while(getline(file, line)){
                //Explode string by , delimiter and put values in
                std::vector<std::string> attributes;
                std::stringstream ss(line);
                std::string value;
                while(getline(ss, value, delimiter)){
                    attributes.push_back(value);
                }
                std::string weightClassCheck = attributes[0].substr(0,3);
                if(isInteger(weightClassCheck)){
                    //At a row that holds the headers
                    weightClass = attributes[0];
                }
                else{
                    //At a row that has fighter values
                    Fighter *f = new Fighter(attributes[NAME], weightClass);
                    f->setFighterStats(
                            atof(attributes[STRIKING].c_str()),
                            atof(attributes[GRAPPLING].c_str()),
                            atof(attributes[STAMINA].c_str()),
                            atof(attributes[HEALTH].c_str()),
                            atof(attributes[OVERALL].c_str())
                    );
                    logger.notice(f->getName() + " " + f->getWeightClass());
                }
            }
        }
    };
}

#endif //UFC_SIMULATOR_ROSTER_H
