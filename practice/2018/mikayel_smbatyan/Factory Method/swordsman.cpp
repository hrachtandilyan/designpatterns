#include "swordsman.h"
//swordsman 
void swordsman::attack(warrior& target)
{
    //TODO
}
void swordsman::protect(warrior&)
{
    //TODO
}
void swordsman::recover()
{
    //TODO
}
void swordsman::harakiri()
{
    //TODO
}



//swordsman factory 
warrior* const swordsman_factory::create_warrior() const
{
    return new swordsman(random_property_initializer(mers_twist),
                        random_property_initializer(mers_twist),
                        random_property_initializer(mers_twist));
}