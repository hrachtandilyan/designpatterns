#include <iostream>
#include <math.h>
using namespace std;

class AbstractCarA {
 public:
  virtual ~AbstractCarA(){};
  virtual std::string UsefulFunctionA() const = 0;
};


class ConcreteCarA1 : public AbstractCarA {
 public:
  std::string UsefulFunctionA() const override {
    return "The result of the Car A1.";
  }
};

class ConcreteCarA2 : public AbstractCarA {
  std::string UsefulFunctionA() const override {
    return "The result of the Car A2.";
  }
};

class AbstractCarB {
 
 public:
  virtual ~AbstractCarB(){};
  virtual std::string UsefulCarB() const = 0;
  
  virtual std::string AnotherUsefulFunctionB(const AbstractCarA &collaborator) const = 0;
};


class ConcreteCarB1 : public AbstractCarB {
 public:
  std::string UsefulFunctionB() const override {
    return "The result of the Car B1.";
  }
 
  std::string AnotherUsefulFunctionB(const AbstractCarA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B1 collaborating with ( " + result + " )";
  }
};

class ConcreteCarB2 : public AbstractCarB {
 public:
  std::string UsefulFunctionB() const override {
    return "The result of the car B2.";
  }
 
  std::string AnotherUsefulFunctionB(const AbstractCarA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
  }
};


class AbstractFactory {
 public:
  virtual AbstractCarA *CreateCarA() const = 0;
  virtual AbstractCarB *CreateCarB() const = 0;
};


class ConcreteFactory1 : public AbstractFactory {
 public:
  AbstractProductA *CreateCarA() const override {
    return new ConcreteCarA1();
  }
  AbstractProductB *CreateCarB() const override {
    return new ConcreteCarB1();
  }
};


class ConcreteFactory2 : public AbstractFactory {
 public:
  AbstractProductA *CreateCarA() const override {
    return new ConcreteCarA2();
  }
  AbstractProductB *CreateCarB() const override {
    return new ConcreteCarB2();
  }
};



void ClientCode(const AbstractFactory &factory) {
  const AbstractCarA *car_a = factory.CreateCarA();
  const AbstractCarB *car_b = factory.CreateCarB();
  std::cout << car_b->UsefulFunctionB() << "\n";
  std::cout <<car_b->AnotherUsefulFunctionB(*car_a) << "\n";
  delete car_a;
  delete car_b;
}

int main() {
  std::cout << "Client: Testing client code with the first factory type:\n";
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with the second factory type:\n";
  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;