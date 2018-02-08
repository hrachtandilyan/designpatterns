#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class Game {
protected:
	string player_name;
public:
	Game() :player_name("unknown")
	{}
	virtual void greeting() = 0;
	void add_name(const string& name)
	{
		this->player_name = name;
	}
};

class X_0 : public Game
{
public:
	void greeting()
	{
		cout << "X_0 GAME : Hi , " << this->player_name << endl;
	}
};


class Battleship : public Game
{
public:
	void greeting()
	{
		cout << "BATTLESHIP : Hello , " << this->player_name << endl;
	}

};

class X_0_am : public Game
{
public:
	void greeting()
	{
		cout << "X_0 XAX : Bayev , " << this->player_name << endl;
	}
};


class Battleship_am : public Game
{
public:
	
	void greeting()
	{
		cout << " XAX:  Bayev , " << this->player_name << endl;
	}
};

class BaseGameFactory
{
public:
	virtual Game* Create_X_0() = 0;
	virtual Game* Create_Battleship() = 0;
};
class EnGameFactory :public BaseGameFactory
{
public:
	Game * Create_X_0()
	{
		return new X_0();
	}
	Game* Create_Battleship()
	{
		return new Battleship();
	}
};
class AmGameFactory :public BaseGameFactory
{
public:
	Game* Create_X_0()
	{
		return new X_0_am();
	}
	Game* Create_Battleship()
	{
		return new Battleship_am();
	}

};

void play(BaseGameFactory* factory)
{
	Game* battleship = factory->Create_Battleship();
	Game* x_0 = factory->Create_X_0();
	battleship->add_name("Liza");
	x_0->add_name("Artyomchik");
	battleship->greeting();
	x_0->greeting();
}
int main()
{
	BaseGameFactory* factory1 = new EnGameFactory;
	cout << "testing EN" << endl;
	play(factory1);

	BaseGameFactory* factory2 = new AmGameFactory();
	cout << "testing AM" << endl;
	play(factory2);

}