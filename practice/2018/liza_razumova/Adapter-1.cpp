#include <iostream>
using namespace std;
//target
class Show
{
public:
	virtual void black_white() = 0;
};
//adaptee
class ModernShow
{
public:
	virtual void color() = 0;
};

class ModernShowConcrete : public ModernShow
{
public:
	virtual void color() override {}
};

class ShowAdapter : public Show
{
	ModernShow* Mshow;
public:
	ShowAdapter(ModernShow* Mshow)
	{
		this->Mshow = Mshow;
	}
public:
	void black_white()
	{
		Mshow->color();
	}

};
int main()
{
	ModernShow * modern_show = new ModernShowConcrete();
	Show * show_adapter = new ShowAdapter(modern_show);


	cout << "SHOW" << endl;
	show->black_white();

	cout << "B_W" << endl;
	modern_show->color();

	cout << "adapter" << endl;
	show_adapter->black_white();
	return 0;
}