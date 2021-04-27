#include <iostream>
#include <string>
using namespace std;

class Creature {
protected:
    string Head;
    string Body;
    string Hands;
    string Feet;
    string Tail;
public:
    void setHead(string h)
    {
        Head = h;
    }
    void setBody(string b)
    {
        Body = b;
    }
    void setHands(string h)
    {
        Hands = h;
    }
    void setFeet(string f)
    {
        Feet = f;
    }
    void setTail(string t)
    {
        Tail = t;
    }
    void getMessage() {
        cout << "The creature is created!\nHead is like this--> ";
        if(Head == "")
            cout<<"no head\n";
        else
            cout<<Head<<endl;
        
        cout << "Body is like this--> ";
        if(Hands == "")
            cout<<"no body\n";
        else
            cout<<Body<<endl;
        
        cout << "Hands are like this--> ";
        if(Hands == "")
            cout<<"no hands\n";
        else
            cout<<Hands<<endl;
        
        cout << "Feet are like this--> ";
        if(Hands == "")
            cout<<"no feet\n";
        else
            cout<<Feet<<endl;
        
        cout << "Tail is like this--> ";
        if(Tail == "")
            cout<<"no tail\n";
        else
            cout<<Tail<<endl;
    }
};

class BodyBuilder {
public:
    BodyBuilder(){};
    virtual void buildHead(){}
    virtual void buildBody(){}
    virtual void buildHands(){}
    virtual void buildFeet(){}
    virtual void buildTail(){}
    virtual Creature* getCreature(){ return 0;}
};

class Sorcerer : public BodyBuilder
{
private:
    Creature* currentCreature = new Creature;
public:
    void buildHead()
    {
        currentCreature->setHead("wearing an enchanted hood");
    }
    void buildBody()
    {
        currentCreature->setBody("wearing an enchanted robe");
    }
    void buildHands()
    {
        currentCreature->setHands("wearing enchanted gloves");
    }
    void buildFeet()
    {
        currentCreature->setFeet("wearing enchanted boots");
    }
    
    Creature* getCreature()
    {
        return currentCreature;
    }
};
class Undead : public BodyBuilder
{
private:
    Creature* currentCreature = new Creature;
public:
    void buildBody()
    {
        currentCreature->setBody("distorted and putrefied");
    }
    void buildHands()
    {
        currentCreature->setHands("putrefied, dangling from the body");
    }
    void buildFeet()
    {
        currentCreature->setFeet("putrefied");
    }
    Creature* getCreature()
    {
        return currentCreature;
    }
};
class Dragon : public BodyBuilder
{
private:
    Creature* currentCreature = new Creature;
public:
    void buildHead()
    {
        currentCreature->setHead("reptilian, breathes fire");
    }
    void buildBody()
    {
        currentCreature->setBody("reptilian, big");
    }
    void buildHands()
    {
        currentCreature->setHands("wings!");
    }
    void buildFeet()
    {
        currentCreature->setFeet("reptilian, clawed");
    }
    void buildTail()
    {
        currentCreature->setTail("reptilian, long");
    }

    Creature* getCreature()
    {
        return currentCreature;
    }
};

class Director {
private: BodyBuilder* builder;
public:
    Director(BodyBuilder* builder)
    {
        this->builder = builder;
    }
    
    Creature* createCreature()
    {
        builder->buildHead();
        builder->buildBody();
        builder->buildHands();
        builder->buildFeet();
        builder->buildTail();
        return builder->getCreature();
    }
};

class A
{
private: Creature c;
public: void set(Creature c)
    {
        this->c = c;
        cout<<"fuk";
    }
};


int main()
{
    Sorcerer* srcBuilder = new Sorcerer();
    Director dir = *new Director(srcBuilder);
    Creature* sorcerer = dir.createCreature();
    sorcerer->getMessage();
    cout<<endl;
    Undead* undBuilder = new Undead();
    dir = Director(undBuilder);
    Creature* undead = dir.createCreature();
    undead->getMessage();
    cout<<endl;
    Dragon* drgnBuilder = new Dragon();
    dir = Director(drgnBuilder);
    Creature* dragon = dir.createCreature();
    dragon->getMessage();
    cout<<endl;
}
