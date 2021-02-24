//Singleton Design Pattern
#include <iostream>                                                              
#include <string>

class Singleton
{
private:
    std::string str;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

protected:
    Singleton() {}
    ~Singleton() {}

public:
    std::string getData() const
    {
        return str;
    }
    void setData(const std::string& newStr)
    {
        str = newStr;
    }
    static Singleton& Instance()
    {
        static Singleton instance;
        return instance;
    }
};

int main()
{                                           
    Singleton &s = Singleton::Instance();
    s.setData("foo");
    Singleton &s2 = Singleton::Instance();
    s.setData("bar");
 
    std::cout  << &s << '\n';
    std::cout  << &s2 << std::endl;

    return 0;
}