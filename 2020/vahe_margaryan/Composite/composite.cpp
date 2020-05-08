#include <iostream>
#include <list>

#include <stdlib.h>
#include <time.h>

class Netlist
{
public:
  Netlist() = default;
  virtual ~Netlist() = default;

  virtual void Add(Netlist* nl) {};
  virtual void Remove(Netlist* nl) {};

  virtual bool GetSignal() const = 0;

};

class Clock : public Netlist
{
public:
  bool GetSignal() const {
    const int tmp = rand() % 10;
    const bool signal = (tmp & 1) == 0;
    return signal;
  }
};

class Instance : public Netlist
{
public:
  void Add(Netlist* nl) override {
    inputs_.push_back(nl);
  }

  void Remove(Netlist* nl) override {
    inputs_.remove(nl);
  }

  virtual bool GetSignal() const = 0;

protected:
  std::list<Netlist*> inputs_;
};

class AND : public Instance
{
public:
  bool GetSignal() const override {
    for (const auto it : inputs_) {
      if (it->GetSignal() == false)
        return false;
    }
    return true;
  }
};

class OR : public Instance
{
public:
  bool GetSignal() const override {
    for (const auto it : inputs_) {
      if (it->GetSignal() == true)
        return true;
    }
    return false;
  }
};

int main(int argc, char** argv)
{
  srand(time(0));

  Netlist* gate1 = new AND;
  Netlist* gate2 = new AND;
  Netlist* gate3 = new OR;

  gate1->Add(gate2);
  gate1->Add(gate3);

  Netlist* clk1 = new Clock;
  Netlist* clk2 = new Clock;

  gate2->Add(clk1);
  gate2->Add(clk2);

  Netlist* clk3 = new Clock;
  Netlist* clk4 = new Clock;

  gate3->Add(clk3);
  gate3->Add(clk4);

  const bool ans = gate1->GetSignal();

  std::cout << "OUTPUT: " << std::boolalpha << ans << std::endl;

  return 0;
}