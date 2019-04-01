#include <string>

class StringSingleton
{
public:
	std::string GetString() const
	{
		return myString;
	}
	void SetString(const std::string &newStr)
	{
		myString = newStr;
	}

	static StringSingleton &Instance()
	{
		static std::auto_ptr<StringSingleton> instance(new StringSingleton);
		return *instance;
	}

private:
	StringSingleton() {}

	StringSingleton(const StringSingleton &old);

	~StringSingleton() {}
private:
	std::string myString;
};