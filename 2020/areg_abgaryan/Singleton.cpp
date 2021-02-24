#include <iostream>
#include <string>

using namespace std;

class Russia_President
{
private:
	string name = "Putin";

protected:
	Russia_President() = default;
	~Russia_President() = default;

public:
	Russia_President(const Russia_President&) = delete;
	Russia_President& operator=(const Russia_President&) = delete;
	
	Russia_President(const Russia_President&&) noexcept = delete;
	Russia_President& operator=(const Russia_President&&) noexcept = delete;

	string get_value() const
	{
		return name;
	}
	
	void send_president_to_vacation()
	{
		name = "Medvedev";
		cout << "\nMaybe for 4 years only.\n";
	}
	
	static Russia_President& getinstance()
	{
		static Russia_President object;
		return object;
	}
};

void change_president()
{
	cout << "\nThis action is not allowed lol :P. Try after ~20 years\n";
}

int main()
{
	Russia_President &rp = Russia_President::getinstance();
	rp.send_president_to_vacation();
	cout << rp.get_value();
	change_president();
}