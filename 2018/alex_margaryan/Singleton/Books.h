#pragma once

#include <string>

class Books
{
private:
	int _price;
	std::string _name;
	static Books *_book;

	Books()
		:_price(50)
		,_name("BookName")
	{}
public:
	void set_price(int price) 
	{ 
		_price = price;
	}
	int get_price()
	{
		return _price;
	}
	static Books *book()
	{
		if (!_book)
			_book = new Books;
		return _book;
	}
};

