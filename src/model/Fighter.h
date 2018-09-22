/**
*@author Zachary Kakol
*@date 9/15/18
*@email zskakol@gmail.com
*/

#ifndef UFC_SIMULATOR_FIGHTER_H
#define UFC_SIMULATOR_FIGHTER_H

#include <string>
#include <map>


namespace model{
    class Fighter{
    private:
        std::string name;
        int age;
        std::string nickname;
        std::string weightClass;

        double striking;
        double grappling;
        double stamina;
        double health;
        double overall;

        int wins;
        int losses;
        int rank; // 0 is for the champion
    public:
        Fighter(std::string name, std::string weightclass){
            this->name = name;
            this->weightClass = weightclass;
            this->wins = 0;
            this->losses = 0;
        }

        void setFighterStats(double s, double grapple, double stamina, double h, double o){
            this->striking = s;
            this->grappling = grapple;
            this->stamina = stamina;
            this->health = health;
            this->overall = o;
        }

        inline std::string getName(){return this->name;}
        inline int getAge(){return this->age;}
        inline std::string getNickname(){return this->nickname;}
        inline std::string getWeightClass(){return this->weightClass;}

        inline std::map<std::string,double> getStats(){
            return std::map<std::string, double> {
                    {"striking" , this->striking},
                    {"grappling", this->grappling},
                    {"stamina", this->stamina},
                    {"health", this->health},
                    {"overall", this->health}
            };
        }

        void registerWin(){
            this->wins++;
        }

        void registerLoss(){
            this->losses++;
        }

        std::map<std::string, int> getRecord(){
            return std::map<std::string, int>{
                    {"wins", this->wins},
                    {"losses", this->losses}
            };
        }

    };
}


#endif //UFC_SIMULATOR_FIGHTER_H
