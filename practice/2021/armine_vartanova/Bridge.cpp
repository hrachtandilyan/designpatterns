#include <iostream>
using namespace std;

//Implementation
class Material {
 public:
  virtual void melt() const = 0;
};

//Concrete Implementation 1
class Steel : public Material {
 public:
  void melt() const  {
    cout<< "melted steel\n";
  }
};

//Concrete Implementation 2
class Glass : public Material {
 public:
  void melt() const  {
    cout<< "melted glass\n";
  }
};

//Concrete Implementation 3
class Dragonbone : public Material {
 public:
  void melt() const  {
    cout<< "melted dragonbone\n";
  }
};

//Abstraction
class Object {
 protected:
  Material* material;

 public:
  Object(Material* mat) : material(mat) {}
  virtual void forge() const {
      cout<< "Forged an object using ";
    this->material->melt();
  }
};

//Refined Abstraction 1
class Armor : public Object {
 public:
  Armor(Material* material) : Object(material) {}
  void forge() const override {
      cout<< "Forged armor using ";
      this->material->melt();
  }
};

//Refined Abstraction 2
class Weapon : public Object {
 public:
  Weapon(Material* material) : Object(material) {}
  void forge() const override {
      cout<< "Forged weapon using ";
      this->material->melt();
  }
};

int main() {
  Material* material = new Glass;
  Object* obj = new Object(material);
  obj->forge();

  material = new Steel;
  obj = new Armor(material);
  obj->forge();
    
  material = new Dragonbone;
  obj = new Weapon(material);
  obj->forge();
}
