 #include <iostream>
#include <map>
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

/*
 //Factory method using templates
 //We'll be using the base class and its subclasses defined above
 //Using templates, we won't have to create a subclass factory for each product type
 
 class ArmorFactory {
 public:
     virtual Armor* CreateArmor() = 0;
 };
 
template <class ArmorType>
class ArmorCreator: public ArmorFactory {
    public:
    virtual Armor* CreateArmor();
};

template <class ArmorType>
Armor* ArmorCreator<ArmorType>::CreateArmor()
{
    cout<<typeid(ArmorType).name()<<" forged\n";
    return new ArmorType;
}
*/

/*
 If we use templates, all the factory classes
 defined below will have to be deleted
 */
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

/*
 //Factory method using templates
 
    ArmorCreator<Armor> standardArmorFactory;
    standardArmorFactory.CreateArmor();
     
    ArmorCreator<DragonboneArmor> dragonboneArmorFactory;
    dragonboneArmorFactory.CreateArmor();
    
    ArmorCreator<ElvenArmor> elvenArmorFactory;
    elvenArmorFactory.CreateArmor();
    
    ArmorCreator<DaedricArmor> daedricArmorFactory;
    daedricArmorFactory.CreateArmor();
*/
}
