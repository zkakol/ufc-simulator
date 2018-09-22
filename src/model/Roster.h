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
        std::vector<Fighter*> allFighters;

        std::vector<Fighter*> flyweight;
        std::vector<Fighter*> bantamweight;
        std::vector<Fighter*> featherweight;
        std::vector<Fighter*> lightweight;
        std::vector<Fighter*> welterweight;
        std::vector<Fighter*> middleweight;
        std::vector<Fighter*> lightHeavyweight;
        std::vector<Fighter*> heavyweight;

        std::vector<Fighter*> wstrawweight;
        std::vector<Fighter*> wbantamweight;

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
                    this->allFighters.push_back(f);
                    if(weightClass == "125") this->flyweight.push_back(f);
                    if(weightClass == "135") this->bantamweight.push_back(f);
                    if(weightClass == "145") this->featherweight.push_back(f);
                    if(weightClass == "155") this->lightweight.push_back(f);
                    if(weightClass == "170") this->welterweight.push_back(f);
                    if(weightClass == "185") this->middleweight.push_back(f);
                    if(weightClass == "205") this->lightHeavyweight.push_back(f);
                    if(weightClass == "265") this->heavyweight.push_back(f);
                    if(weightClass == "115w") this->wstrawweight.push_back(f);
                    if(weightClass == "135w") this->wbantamweight.push_back(f);
                }
            }
        }

        Fighter* getRandomFighter(){
            srand(time(0));
            int randomIndex = rand() % allFighters.size();
            //int randomIndex = (int)(((((double)std::rand()) / RAND_MAX) * allFighters.size()) + 1);
            return allFighters[randomIndex];
        }
    };
}

#endif //UFC_SIMULATOR_ROSTER_H
