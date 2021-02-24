/* 
 * File:   swordsman.h
 * Author: mikayel
 *
 * Created on February 21, 2018, 10:02 PM
 */

#ifndef SWORDSMAN_H
#define SWORDSMAN_H
#include "warrior.h"

/*
 * Concrete Product in the Factory method Structure
 */
class swordsman: public warrior
{
    size_t _onehanded_damage_;
    size_t _twohanded_damage_;
    
public:
    
    typedef size_t health_swordsman;
    typedef size_t onehanded;
    typedef size_t twohanded;
    
    
    virtual void attack(warrior&);
    virtual void protect(warrior&);
    virtual void recover();
    virtual void harakiri();
    
    swordsman(health_swordsman health, onehanded onehanded_damage, twohanded twohanded_damage)
            :warrior(health), 
            _onehanded_damage_(onehanded_damage),
            _twohanded_damage_(twohanded_damage){}
    virtual ~swordsman() = default;

};

// Concrete Creator
class swordsman_factory: public warrior_factory
{
    warrior* const create_warrior() const;
};


#endif /* SWORDSMAN_H */

