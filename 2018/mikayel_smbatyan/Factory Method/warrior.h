/* 
 * File:   Warrior.h
 * Author: mikayel
 *
 * Created on February 21, 2018, 9:33 PM
 */

#ifndef WARRIOR_H
#define WARRIOR_H
#include <random>
/*
 * Global devices for further realization. 
 */
std::random_device rd;
std::mt19937 mers_twist(rd());
std::uniform_int_distribution<uint32_t> random_property_initializer(50,65); // Initial created warrior property setter



/*
 * The Product class of the Factory Method Structure
 */

class warrior
{
protected:
    size_t _health_;
public:
    warrior(size_t health):_health_(health){}
    virtual void attack(warrior&) = 0;
    virtual void protect(warrior&) = 0;
    virtual void recover() = 0;
    virtual void harakiri() = 0;
    virtual ~warrior() = default;

};

/*
 * The Creator class of the Factory Method Structure
 */
class warrior_factory
{
public:
    warrior* create_warrior() const; 
};


#endif /* WARRIOR_H */

