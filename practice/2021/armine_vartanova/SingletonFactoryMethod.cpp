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
    static ArmorFactory& getInstance(){
        static ArmorFactory instance;
        return instance;
      }
    virtual Armor* CreateArmor()
    {
        cout<<"Standard armor forged\n";
        return new Armor();
    };
    
    protected:
    ArmorFactory()= default;
    ~ArmorFactory()= default;
    ArmorFactory(const ArmorFactory&)= delete;
    ArmorFactory& operator=(const ArmorFactory&)= delete;
};

class DragonboneArmorFactory : public ArmorFactory {
    public:
    static DragonboneArmorFactory& getInstance(){
        static DragonboneArmorFactory instance;
        return instance;
      }
    Armor* CreateArmor()
    {
        cout<<"Dragonbone armor forged\n";
        return new DragonboneArmor();
    }
};
class ElvenArmorFactory : public ArmorFactory {
    public:
    static ElvenArmorFactory& getInstance(){
        static ElvenArmorFactory instance;
        return instance;
    }
    Armor* CreateArmor()
    {
        cout<<"Elven armor forged\n";
        return new ElvenArmor();
    }
};
class DaedricArmorFactory : public ArmorFactory {
    public:
    static DaedricArmorFactory& getInstance(){
        static DaedricArmorFactory instance;
        return instance;
    }
    Armor* CreateArmor()
    {
        cout<<"Daedric armor forged\n";
        return new DaedricArmor();
    }
};

int main() {
    
    ArmorFactory& standardFactory = ArmorFactory::getInstance();
    standardFactory.CreateArmor();
    
    DragonboneArmorFactory& dragonboneFactory = DragonboneArmorFactory::getInstance();
    dragonboneFactory.CreateArmor();
    
    DaedricArmorFactory& daedricFactory = DaedricArmorFactory::getInstance();
    daedricFactory.CreateArmor();
    
    ElvenArmorFactory& elvenFactory = ElvenArmorFactory::getInstance();
    elvenFactory.CreateArmor();
}


