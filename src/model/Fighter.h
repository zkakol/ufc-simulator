/**
*@author Zachary Kakol
*@date 9/15/18
*@email zskakol@gmail.com
*/

#ifndef UFC_SIMULATOR_FIGHTER_H
#define UFC_SIMULATOR_FIGHTER_H

namespace model{
    class Fighter{
    private:
        std::string name;
        int age;
        std::nickname nickname;
        int weightClass;

        double striking;
        double grappling;
        double stamina;
        double health;
        double overall;
    public:
        Fighter(std::string name, int age, std::nickname, int weightclass){
            this->name = name;
            this->age = age;
            this->nickname = nickname;
            this->weightClass = weightclass;
        }

        void setFighterStats(double s, double grapple, double stamina, double h, double o){
            this->striking = s;
            this->grappling = grapple;
            this->stamina = stamina;
            this->health = health;
            this->overall = o;
        }

        inline static std::string getName(){return this->name;}
        inline static int getAge(){return this->age;}
        inline static std::string getNickname(){return this->nickname;}
        inline static int getWeightClass(){return this->weightClass;}

        inline static map<std::string,double> getStatus(){
            return map<std::string, double> stats{
                    {"striking" , this->striking},
                    {"grappling", this->grappling},
                    {"stamina", this->stamina},
                    {"health", this->health},
                    {"overall", this->health}
            };
        }

    };
}


#endif //UFC_SIMULATOR_FIGHTER_H
