#include <iostream>
#include <string>

class Account_Interface
{
public:
	virtual void cashÎut() = 0;
	virtual ~Account_Interface() {}
};

class BankAccount : public Account_Interface
{
public:
	BankAccount() {}
	void cashÎut() override
	{
		std::cout <<  "You've withdrawed 50 dollars\n";
	}
};

class AccountProxy : public Account_Interface
{
public:
	AccountProxy(BankAccount& b) : bank_(b), pswd_("hello"), active(false) {}
	
	void cashÎut() override
	{
		if (active)
			bank_.cashÎut();
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
	BankAccount acc;

	AccountProxy proxy (acc);
	proxy.cashÎut();
	proxy.authorize("123");
	proxy.authorize("hello");
	proxy.cashÎut();

	return 0;
}
