#pragma once
#include <string>
using namespace std;

class Bike
{
private:
	string _frame;
	string _wheels;
	string _handlebar;

public:
	void set_frame(string frame) { _frame = frame; }
	void set_wheels(string wheels) { _wheels = wheels; }
	void set_handlebar(string handlebar) { _handlebar = handlebar; }
	string get_frame() { return _frame; }
	string get_wheels() { return _wheels; }
	string get_handlebar() { return _handlebar; }
};

