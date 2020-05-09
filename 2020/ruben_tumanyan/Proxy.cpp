#include <iostream>
#include <string>

class Account_Interface
{
public:
	virtual void cash�ut() = 0;
	virtual ~Account_Interface() {}
};

class BankAccount : public Account_Interface
{
public:
	BankAccount() {}
	void cash�ut() override
	{
		std::cout <<  "You've withdrawed 50 dollars\n";
	}
};

class AccountProxy : public Account_Interface
{
public:
	AccountProxy(BankAccount& b) : bank_(b), pswd_("hello"), active(false) {}
	
	void cash�ut() override
	{
		if (active)
			bank_.cash�ut();
		else
			std::cout << "Please authorize\n";
	}

	void authorize(const std::string& password)
	{
		if (pswd_ == password)
			active = true;
		else
			std::cout << "Wrong password, try again\n";
	}
private:
	BankAccount& bank_;
	std::string pswd_;
	bool active;
};

int main()
{
	BankAccount bank;

	AccountProxy proxy (bank);
	proxy.cash�ut();
	proxy.authorize("123");
	proxy.authorize("hello");
	proxy.cash�ut();

	return 0;
}