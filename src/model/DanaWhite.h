/**
*@author Zachary Kakol
*@date 9/15/18
*@email zskakol@gmail.com
*/

#ifndef UFC_SIMULATOR_DANAWHITE_H
#define UFC_SIMULATOR_DANAWHITE_H

#include <iostream>
#include "Fighter.h"
#include "FightAbstract.h"

namespace model{
    class DanaWhite : public FightAbstract{
    public:
        void sayHeWasNeverMyFriend(Fighter *fighter){
            std::cout << "\"" << fighter->getName() << " was never my friend!\" -- Dana White" ;
        }

    };
}

#endif //UFC_SIMULATOR_DANAWHITE_H
