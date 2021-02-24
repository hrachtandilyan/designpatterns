#include <iostream>
#include "Books.h"

using namespace std;
Books *Books::_book = 0;

int main()
{
	cout << Books::book()->get_price() << endl;
	Books::book()->set_price(100);
	cout << Books::book()->get_price() << endl;
	Books::book()->set_price(200);
	cout << Books::book()->get_price() << endl;

	system("pause");
}