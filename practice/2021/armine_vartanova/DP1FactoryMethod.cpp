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

//Base product types (subclasses)
class Gauntlets : public Armor
{
   void setDefence(){
       defence = 10;
    }
};
class Headgear : public Armor
{
    void setDefence(){
        defence = 20;
     }
};
class Cuirass : public Armor
{
    void setDefence(){
        defence = 50;
     }
};
class Boots : public Armor
{
    void setDefence(){
        defence = 30;
     }
};

//Dragonbone armor
class DragonboneGauntlets : public Gauntlets {
    void setDefence(){
        defence = 20;
     }
};
class DragonboneHeadgear : public Headgear {
    void setDefence(){
        defence = 30;
     }
};
class DragonboneCuirass : public Cuirass {
    void setDefence(){
        defence = 60;
     }
};
class DragonboneBoots : public Boots {
    void setDefence(){
        defence = 40;
     }
};

enum ArmorPiece { HEADGEAR, BOOTS, CUIRASS, GAUNTLETS };

//set of products a character can acquire
class Equipment {
private: map<ArmorPiece,Armor*> _equipment;
public:
    void AddGauntlets(Gauntlets* g)
    {
        if (_equipment.find(GAUNTLETS) == _equipment.end())
        {
            _equipment.insert({GAUNTLETS,g});
        }
    }
    
    void AddCuirass(Cuirass* c)
    {
        if (_equipment.find(CUIRASS) == _equipment.end())
        {
            _equipment.insert({CUIRASS,c});
        }
    }
    
    void AddHeadgear(Headgear* h)
    {
        if (_equipment.find(HEADGEAR) == _equipment.end())
        {
            _equipment.insert({HEADGEAR,h});
        }
    }
    
    void AddBoots(Boots* b)
    {
        if (_equipment.find(BOOTS) == _equipment.end())
        {
            _equipment.insert({BOOTS,b});
        }
    }
};

//Creator
class EquipArmor {
    public:
    Equipment* CreateEquipment();
    
    virtual Equipment* MakeEquipment() const
    { return new Equipment; }
    
    virtual Gauntlets* MakeGauntlets() const
    { cout<<"Standard gauntlets created."<<endl;
        return new Gauntlets;   }
    virtual Headgear* MakeHeadgear() const
    { cout<<"Standard headgear created."<<endl;
        return new Headgear; }
    virtual Cuirass* MakeCuirass() const
    { cout<<"Standard cuirass created."<<endl;
        return new Cuirass; }
    virtual Boots* MakeBoots() const
    { cout<<"Standard boots created."<<endl;
        return new Boots; }
};

Equipment* EquipArmor::CreateEquipment () {
    Equipment* equipment = MakeEquipment();
    Gauntlets* gauntlets = MakeGauntlets();
    Headgear* headgear = MakeHeadgear();
    Cuirass* cuirass = MakeCuirass();
    Boots* boots = MakeBoots();
    equipment->AddGauntlets(gauntlets);
    equipment->AddHeadgear(headgear);
    equipment->AddCuirass(cuirass);
    equipment->AddBoots(boots);
    cout<<"Full armor equipped."<<endl;
    return equipment;
}

class EquipDragonboneArmor : public EquipArmor {
    public:
    virtual Gauntlets* MakeGauntlets() const
    {
        cout<<"Dragonbone gauntlets created."<<endl;
        return new DragonboneGauntlets;
    }
    virtual Headgear* MakeHeadgear() const
    {
        cout<<"Dragonbone headgear created."<<endl;
        return new DragonboneHeadgear;
    }
    virtual Cuirass* MakeCuirass() const
    {
        cout<<"Dragonbone cuirass created."<<endl;
        return new DragonboneCuirass;
    }
    virtual Boots* MakeBoots() const
    {
        cout<<"Dragonbone boots created."<<endl;
        return new DragonboneBoots;
    }
};

int main() {
 EquipArmor* eq = new EquipArmor(); //swap to EquipDragonboneArmor() to see changes
 eq->CreateEquipment();
}
