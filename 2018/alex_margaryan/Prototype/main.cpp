#include <iostream>
#include <string>
#include "Account.h"
#include "Client.h"

using namespace std;

int main()
{
	string accountName;
	cout << "Please enter one of the following words: 'facebook', 'google' or 'youtube'" << endl;
	cin >> accountName;

	Account *account;
	account = Client::makeAccount(accountName);
	account->print();

	system("pause");
}