#include <iostream>
#include <stdio.h>
using namespace std;

class InventoryObject
{
protected: int price;
public:
    InventoryObject(){};
    InventoryObject(InventoryObject* obj)
    {
        this->price = obj->price;
    }
    virtual InventoryObject* clone() const
    { return new InventoryObject(*this); }
};

class Armor : InventoryObject
{
protected: int defence;
public:
    Armor(){};
    Armor(Armor* armor)
    {
        this->price = armor->price;
        this->defence = armor->defence;
    }
    virtual Armor* clone() const
    {
        cout<<"Standard Armor cloned\n";
        return new Armor(*this);
    }
};

class Weapon : InventoryObject
{
protected: int damage;
public:
    Weapon(){};
    Weapon(Weapon* weapon)
    {
        this->price = weapon->price;
        this->damage = weapon->damage;
    }
    virtual Weapon* clone() const
    {
        cout<<"Standard Weapon cloned\n";
        return new Weapon(*this);
        
    }
};

class Potion : InventoryObject
{
protected: string effect;
public:
    Potion(){};
    Potion(Potion* potion)
    {
        this->price = potion->price;
        this->effect = potion->effect;
    }
    virtual Potion* clone() const
    {
        cout<<"Standard Potion cloned\n";
        return new Potion(*this);
    }
};

class ElvenArmor : public Armor
{
public:
    virtual ElvenArmor* clone() const
    {
        cout<<"Elven Armor cloned\n";
        return new ElvenArmor(*this);
    }
};

class ElvenWeapon : public Weapon
{
    virtual ElvenWeapon* clone() const
    {
        cout<<"Elven Weapon cloned\n";
        return new ElvenWeapon(*this);
        
    }
};
class Poison : public Potion
{
public:
    virtual Poison* clone() const
    {
        cout<<"Poison cloned\n";
        return new Poison(*this);
    }
};

class GlassArmor : public Armor
{
public:
    virtual GlassArmor* clone() const
    {
        cout<<"Glass Armor cloned\n";
        return new GlassArmor(*this);
    }
};

class GlassWeapon : public Weapon
{
    virtual GlassWeapon* clone() const
    {
        cout<<"Glass Weapon cloned\n";
        return new GlassWeapon(*this);
        
    }
};
class HealingPotion : public Potion
{
public:
    virtual HealingPotion* clone() const
    {
        cout<<"Healing Potion cloned\n";
        return new HealingPotion(*this);
    }
};

class Inventory
{
private:
    Armor* armor;
    Weapon* weapon;
    Potion* potion;
public:
    Inventory(){};
    void setArmor(Armor* armor)
    {
        this->armor = armor;
    }
    void setWeapon(Weapon* weapon)
    {
        this->weapon = weapon;
    }
    void setPotion(Potion* potion)
    {
        this->potion = potion;
    }
};

class InventoryPrototypeFactory {
private:
    Inventory* prototypeInventory;
    Armor* prototypeArmor;
    Weapon* prototypeWeapon;
    Potion* prototypePotion;
public:
    InventoryPrototypeFactory(Inventory* i, Armor* a, Weapon* w, Potion* p)
    {
        prototypeInventory = i;
        prototypeArmor = a;
        prototypeWeapon = w;
        prototypePotion = p;
    }

    virtual Inventory* makeInventory() const
    {
        return new Inventory;
    }
    virtual Armor* makeArmor() const
    {
        return prototypeArmor->clone();
    }
    virtual Weapon* makeWeapon() const
    {
        return prototypeWeapon->clone();
    }
    virtual Potion* makePotion() const
    {
        return prototypePotion->clone();
    }
};


class InventoryCreator {
    public:
    Inventory* CreateInventory(InventoryPrototypeFactory& factory)
    {
        Inventory* inventory = factory.makeInventory();
        Armor* armor = factory.makeArmor();
        Weapon* weapon = factory.makeWeapon();
        Potion* potion = factory.makePotion();
        inventory->setArmor(armor);
        inventory->setWeapon(weapon);
        inventory->setPotion(potion);
        return inventory;
    }
};

int main()
{
    InventoryCreator inv;
    Inventory* inventory = new Inventory();
    
    
    cout<<"Pick an armor type: Standard | Elven | Glass\n";
    string inventoryPiece;
    cin>>inventoryPiece;
    Armor* armor;
    if(inventoryPiece == "Standard") {armor = new Armor();}
    else if(inventoryPiece == "Elven") {armor = new ElvenArmor();}
    else if(inventoryPiece == "Glass") {armor = new GlassArmor();}
    else {cout<<"Invalid armor type input."; return 0;}
    
    cout<<"Pick a weapon type: Standard | Elven | Glass\n";
    cin>>inventoryPiece;
    Weapon* weapon;
    if(inventoryPiece == "Standard") {weapon = new Weapon();}
    else if(inventoryPiece == "Elven") {weapon = new ElvenWeapon();}
    else if(inventoryPiece == "Glass") {weapon = new GlassWeapon();}
    else {cout<<"Invalid weapon type input."; return 0;}

    cout<<"Pick a potion type: Standard | Poison | Healing\n";
    cin>>inventoryPiece;
    Potion* potion;
    if(inventoryPiece == "Standard") {potion = new Potion();}
    else if(inventoryPiece == "Poison") {potion = new Poison();}
    else if(inventoryPiece == "Healing") {potion = new HealingPotion();}
    else {cout<<"Invalid potion type input."; return 0;}

    InventoryPrototypeFactory inventoryFactory(inventory,armor,weapon,potion);
    inv.CreateInventory(inventoryFactory);
}
