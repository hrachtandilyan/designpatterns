#include <iostream>
#include <map>
using namespace std;

/*
Not necessary to have a base class for armor parts, but we're
including it since all the armor parts have the same functionality
 */
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

//Product family
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

//Product subclass family
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

//Product subclass family
class ElvenGauntlets : public Gauntlets {
    void setDefence(){
        defence = 15;
     }
};
class ElvenHeadgear : public Headgear {
    void setDefence(){
        defence = 25;
     }
};
class ElvenCuirass : public Cuirass {
    void setDefence(){
        defence = 55;
     }
};
class ElvenBoots : public Boots {
    void setDefence(){
        defence = 35;
     }
};

enum ArmorPiece { HEADGEAR, BOOTS, CUIRASS, GAUNTLETS };

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

class ArmorFactory
{
public:
    virtual Equipment* MakeEquipment() const
    { return new Equipment; }
    
    virtual Gauntlets* MakeGauntlets() const
    { cout<<"Standard gauntlets forged."<<endl;
        return new Gauntlets;   }
    virtual Headgear* MakeHeadgear() const
    { cout<<"Standard headgear forged."<<endl;
        return new Headgear; }
    virtual Cuirass* MakeCuirass() const
    { cout<<"Standard cuirass forged."<<endl;
        return new Cuirass; }
    virtual Boots* MakeBoots() const
    { cout<<"Standard boots forged."<<endl;
        return new Boots; }
};

class DragonboneArmorFactory : public ArmorFactory {
    public:
    virtual Gauntlets* MakeGauntlets() const
    {
        cout<<"Dragonbone gauntlets forged."<<endl;
        return new DragonboneGauntlets;
    }
    virtual Headgear* MakeHeadgear() const
    {
        cout<<"Dragonbone headgear forged."<<endl;
        return new DragonboneHeadgear;
    }
    virtual Cuirass* MakeCuirass() const
    {
        cout<<"Dragonbone cuirass forged."<<endl;
        return new DragonboneCuirass;
    }
    virtual Boots* MakeBoots() const
    {
        cout<<"Dragonbone boots forged."<<endl;
        return new DragonboneBoots;
    }
};

class ElvenArmorFactory : public ArmorFactory {
    public:
    virtual Gauntlets* MakeGauntlets() const
    {
        cout<<"Elven gauntlets forged."<<endl;
        return new ElvenGauntlets;
    }
    virtual Headgear* MakeHeadgear() const
    {
        cout<<"Elven headgear forged."<<endl;
        return new ElvenHeadgear;
    }
    virtual Cuirass* MakeCuirass() const
    {
        cout<<"Elven cuirass forged."<<endl;
        return new ElvenCuirass;
    }
    virtual Boots* MakeBoots() const
    {
        cout<<"Elven boots forged."<<endl;
        return new ElvenBoots;
    }
};

class ArmorCreator {
    public:
    Equipment* CreateEquipment(ArmorFactory& factory);
};
Equipment* ArmorCreator::CreateEquipment (ArmorFactory& factory) {
    Equipment* equipment = factory.MakeEquipment();
    Gauntlets* gauntlets = factory.MakeGauntlets();
    Headgear* headgear = factory.MakeHeadgear();
    Cuirass* cuirass = factory.MakeCuirass();
    Boots* boots = factory.MakeBoots();
    equipment->AddGauntlets(gauntlets);
    equipment->AddHeadgear(headgear);
    equipment->AddCuirass(cuirass);
    equipment->AddBoots(boots);
    cout<<"Full armor equipped."<<endl;
    return equipment;
}

int main() {
    ArmorCreator equipment;
    cout<<"Select armor type:\n1.Standard\n2.Dragonbone\n3.Elven\nInput the according number:";
    int armor_num;
    cin>>armor_num;
    if(armor_num == 1)
    {
        ArmorFactory standardFactory;
        equipment.CreateEquipment(standardFactory);
    }
    else if(armor_num == 2)
    {
        DragonboneArmorFactory dragonboneFactory;
        equipment.CreateEquipment(dragonboneFactory);
    }
    else if(armor_num == 3)
    {
        ElvenArmorFactory elvenFactory;
        equipment.CreateEquipment(elvenFactory);
    }
    else cout<<"Invalid input\n";
}
