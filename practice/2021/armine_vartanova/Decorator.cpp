#include <iostream>
using namespace std;

class Jewelry{
 public:
  virtual void create() const = 0;
};

class Amulet : public Jewelry {
public:
  void create() const override
    {
        cout<< "Amulet created\n";
    }
};

class Ring : public Jewelry {
public:
  void create() const override
    {
        cout<< "Ring created\n";
    }
};

class JewelryDecorator : public Jewelry {
protected:
  Jewelry* jwl;

public:
    JewelryDecorator(Jewelry* j) : jwl(j) {}
    void create() const override
    {
        this->jwl->create();
    }
};
class EnchantedJewelryDecorator : public JewelryDecorator {
public:
  EnchantedJewelryDecorator(Jewelry* j) : JewelryDecorator(j) {}
  void create() const override
  {
      cout<<"Enchanted ";
      JewelryDecorator::create();
  }
};

class CursedJewelryDecorator : public JewelryDecorator {
 public:
  CursedJewelryDecorator(Jewelry* j) : JewelryDecorator(j) {}

  void create() const override
  {
      cout<<"Cursed ";
      JewelryDecorator::create();
  }
};

int main() {
  Jewelry* basicAmulet = new Amulet;
  basicAmulet->create();
    
  Jewelry* decorator1 = new EnchantedJewelryDecorator(basicAmulet);
  Jewelry* decorator2 = new CursedJewelryDecorator(decorator1);
  decorator2->create();
    
  Jewelry* basicRing = new Ring;
  decorator1 = new EnchantedJewelryDecorator(basicRing);
  decorator1->create();
}
