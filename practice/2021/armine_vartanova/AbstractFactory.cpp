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

class Equipment {
private:
    Gauntlets* g;
    Cuirass* c;
    Headgear* h;
    Boots* b;
public:
    void setGauntlets(Gauntlets* g)
    {
        this->g = g;
    }
    void  setCuirass(Cuirass* c)
    {
        this->c = c;
    }
    void setHeadgear(Headgear* h)
    {
        this->h = h;
    }
    void setBoots(Boots* b)
    {
        this->b = b;
    }
};

class ArmorFactory
{
public:
    virtual Equipment* makeEquipment() const
    {
        return new Equipment;        
    }
    
    virtual Gauntlets* makeGauntlets() const
    {
        cout<<"Standard gauntlets forged."<<endl;
        return new Gauntlets;
        
    }
    virtual Headgear* makeHeadgear() const
    {
        cout<<"Standard headgear forged."<<endl;
        return new Headgear;
        
    }
    virtual Cuirass* makeCuirass() const
    {
        cout<<"Standard cuirass forged."<<endl;
        return new Cuirass;
        
    }
    virtual Boots* makeBoots() const
    {
        cout<<"Standard boots forged."<<endl;
        return new Boots;
        
    }
};

class DragonboneArmorFactory : public ArmorFactory {
    public:
    virtual Gauntlets* makeGauntlets() const
    {
        cout<<"Dragonbone gauntlets forged."<<endl;
        return new DragonboneGauntlets;
    }
    virtual Headgear* makeHeadgear() const
    {
        cout<<"Dragonbone headgear forged."<<endl;
        return new DragonboneHeadgear;
    }
    virtual Cuirass* makeCuirass() const
    {
        cout<<"Dragonbone cuirass forged."<<endl;
        return new DragonboneCuirass;
    }
    virtual Boots* makeBoots() const
    {
        cout<<"Dragonbone boots forged."<<endl;
        return new DragonboneBoots;
    }
};

class ElvenArmorFactory : public ArmorFactory {
    public:
    virtual Gauntlets* makeGauntlets() const
    {
        cout<<"Elven gauntlets forged."<<endl;
        return new ElvenGauntlets;
    }
    virtual Headgear* makeHeadgear() const
    {
        cout<<"Elven headgear forged."<<endl;
        return new ElvenHeadgear;
    }
    virtual Cuirass* makeCuirass() const
    {
        cout<<"Elven cuirass forged."<<endl;
        return new ElvenCuirass;
    }
    virtual Boots* makeBoots() const
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
    Equipment* equipment = factory.makeEquipment();
    Gauntlets* gauntlets = factory.makeGauntlets();
    Headgear* headgear = factory.makeHeadgear();
    Cuirass* cuirass = factory.makeCuirass();
    Boots* boots = factory.makeBoots();
    equipment->setGauntlets(gauntlets);
    equipment->setHeadgear(headgear);
    equipment->setCuirass(cuirass);
    equipment->setBoots(boots);
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

