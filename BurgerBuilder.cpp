#include <string>
#include <iostream>

class HamBurger
{
public:
	void setPrice(int price)
	{
		b_price = price;
	}
	void setType(const std::string& type)
	{
		b_type = type;
	}
	void setSize(const std::string& size)
	{
		b_size = size;
	}
	void infoAboutBurger()
	{
		std::cout << "Burger size is: " << b_size << " , price is: " << b_price << " , type is: " << b_type << std::endl;
	}
private:
	std::string b_price;
	std::string b_type;
	std::string b_size;
};

class HamBurgerBuilder
{
public:
	~HamBurgerBuilder() {};

	HamBurger* getBurger()
	{
		return my_burger.release();
	}
	void createNewBurger()
	{
		my_burger = std::make_unique<HamBurger>();
	}
	void buildDough()
	{
		my_burger->setPrice(100);
	}
protected:
	std::unique_ptr<HamBurger> my_burger;
};

class Cook
{
public:
	void infoAboutBurger()
	{
		my_burgerBuilder->getBurger()->infoAboutBurger();
	}
	void makeBurger(HamBurgerBuilder* burgBuild)
	{
		my_burgerBuilder = burgBuild;
		my_burgerBuilder->createNewBurger();
	}
private:
	HamBurgerBuilder* my_burgerBuilder;
};