#include <iostream>
using namespace std;

//Base product class
class Armor {
protected: int defence;
public:
    void TakeDamage(int damage)
    {
        defence -= damage;
    }
protected:
    void setDefence();
};

//Base product types
class DragonboneArmor : public Armor
{
   void setDefence(){
       defence = 100;
    }
};
class ElvenArmor : public Armor
{
    void setDefence(){
        defence = 70;
     }
};
class DaedricArmor : public Armor
{
    void setDefence(){
        defence = 90;
     }
};

//Creator
class ArmorFactory {
    public:
    virtual Armor* CreateArmor()
    {
        cout<<"Standard armor forged\n";
        return new Armor();
    };
};

class DragonboneArmorFactory : public ArmorFactory {
    public:
    Armor* CreateArmor()
    {
        cout<<"Dragonbone armor forged\n";
        return new DragonboneArmor();
    }
};
class ElvenArmorFactory : public ArmorFactory {
    public:
    Armor* CreateArmor()
    {
        cout<<"Elven armor forged\n";
        return new ElvenArmor();
    }
};
class DaedricArmorFactory : public ArmorFactory {
    public:
    Armor* CreateArmor()
    {
        cout<<"Daedric armor forged\n";
        return new DaedricArmor();
    }
};

int main() {
    
    ArmorFactory* standardArmor = new ArmorFactory();
    standardArmor->CreateArmor();
    
    ArmorFactory* dragonboneArmor = new ArmorFactory();
    dragonboneArmor->CreateArmor();
    
    ArmorFactory* daedricArmor = new DaedricArmorFactory();
    daedricArmor->CreateArmor();
    
    ArmorFactory* elvenArmor = new ElvenArmorFactory();
    elvenArmor->CreateArmor();
}


