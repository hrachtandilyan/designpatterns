#include <iostream>

class PlayerMemento
{
public:
	virtual ~PlayerMemento() {}

private:
	friend class Player;

	PlayerMemento(int h) : health_(h) {}
	int getState() const
	{
		return health_;
	}
	void setState(int h)
	{
		health_ = h;
	}

	int health_;
};


class Player
{
public:
	PlayerMemento* createMemento() const
	{
		return new PlayerMemento(health_);
	}
	void setMemento(const PlayerMemento* m)
	{
		health_ = m->getState();
	}
	Player()
	{
		health_ = 100;
	}
	void getDamage(int d)
	{
		health_ -= d;
	}
	void getCure(int c)
	{
		health_ += c;
	}
	void showHealthBar() const
	{
		if (health_ > 70)
			std::cout << "Green\n";
		else if (health_ > 40)
			std::cout << "Yellow\n";
		else
			std::cout << "Red\n";
	}
private:
	int health_;
};

class GameTools
{
public:
	GameTools() : mem_(nullptr)
	{
	}
	~GameTools() 
	{
		delete mem_;
	}
	void saveState(const Player& p)
	{
		mem_ = p.createMemento();
	}
	void loadState(Player& p) const
	{
		p.setMemento(mem_);
	}
private:
	PlayerMemento* mem_;
};

int main()
{
	GameTools* gTools = new GameTools();
	Player* p = new Player();

	p->getDamage(20);
	p->getCure(5);
	p->showHealthBar();

	gTools->saveState(*p);

	p->getDamage(80);
	p->showHealthBar();

	gTools->loadState(*p);
	p->showHealthBar();

	delete p;
	delete gTools;

	return 0;
}