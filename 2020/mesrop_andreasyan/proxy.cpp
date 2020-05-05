#include <iostream>
#include <string>
using namespace std;

class Shelf {
public:
    virtual void Open() = 0;
    virtual void Close() = 0;
};

class GoldenShelf : public Shelf {
public:
    void Open() { cout << "Opening the golden shelf" << endl; }
    void Close() { cout << "Closing the golden shelf" << endl; }
};

class Security {
public:
    Security(Shelf& shelf): shelf_(shelf) {}
    bool Authenticate(const string& password) { return password == "1234"; }
    void Open(const string& password)
    {
        if (Authenticate(password)) shelf_.Open();
        else cout << "Nope, try again" << endl;
    }
    void Close() { shelf_.Close(); }

private:
    Shelf& shelf_;
};

int main()
{
    GoldenShelf goldenshelf;
    Security secureShelf(goldenshelf);
    secureShelf.Open("password");
    secureShelf.Open("1234");
    secureShelf.Close();
    return 0;
}
