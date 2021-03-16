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

int main() {

   ArmorCreator<Armor> standardArmorFactory;
   standardArmorFactory.CreateArmor();
    
   ArmorCreator<DragonboneArmor> dragonboneArmorFactory;
   dragonboneArmorFactory.CreateArmor();
   
   ArmorCreator<ElvenArmor> elvenArmorFactory;
   elvenArmorFactory.CreateArmor();
   
   ArmorCreator<DaedricArmor> daedricArmorFactory;
   daedricArmorFactory.CreateArmor();
}


