#include <iostream>
using namespace std;

//Adaptee
class MagicKey
{
public:
    void unlock()
    {
        cout<<"unlocked.\n";
    }
  
};
class Chest
{
public:
    void unlockChest()
    {
        cout<<"Chest unlocked.\n";
    }
};
class Door
{
public:
    void unlockDoor()
    {
        cout<<"Door unlocked.\n";
    }
};


/*
 We want MagicKey to unlock anything (e.g. chest and door).
 We'll be using adapters for that.
 */
//Object adapters
class KeyAdapterForChest : public Chest
{
protected:
    MagicKey* magicKey;
public:
    KeyAdapterForChest(MagicKey* key)
    {
        magicKey = key;
    }
    void unlockChest()
    {
        cout<<"Chest ";
        magicKey->unlock();
    }
    
};

class KeyAdapterForDoor : public Door
{
protected:
    MagicKey* magicKey;
public:
    KeyAdapterForDoor(MagicKey* key)
    {
        magicKey = key;
    }
    void unlockDoor()
    {
        cout<<"Door ";
        magicKey->unlock();
    }
};


int main()
{
    MagicKey* key = new MagicKey;
    KeyAdapterForChest* keyAdapterChest = new KeyAdapterForChest(key);
    keyAdapterChest->unlockChest();
    KeyAdapterForDoor* keyAdapterDoor = new KeyAdapterForDoor(key);
    keyAdapterDoor->unlockDoor();
}
