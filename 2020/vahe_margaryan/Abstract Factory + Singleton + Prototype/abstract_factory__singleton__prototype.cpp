#include <iostream>

class Villager
{
public:
  virtual Villager* clone() const = 0;
  virtual void action() const = 0;

  virtual ~Villager()
  {
  }
};

class FrenchVillager : public Villager
{
public:
  Villager* clone() const override
  {
    std::cout << "French villager is created!" << std::endl;
    return new FrenchVillager(*this);
  }

  void action() const override
  {
    std::cout << "French villager is farming!" << std::endl;
  }
};

class SpanishVillager : public Villager
{
public:
  Villager* clone() const override
  {
    std::cout << "Spanish villager is created!" << std::endl;
    return new SpanishVillager(*this);
  }

  void action() const override
  {
    std::cout << "Spanish villager is farming!" << std::endl;
  }
};

class Bakery
{
public:
  virtual Bakery* clone() const = 0;
  virtual void produce() const = 0;

  virtual ~Bakery()
  {
  }
};

class FrenchBakery : public Bakery
{
public:
  Bakery* clone() const override
  {
    std::cout << "French bakery is created!" << std::endl;
    return new FrenchBakery(*this);
  }

  void produce() const override
  {
    std::cout << "French bakery is producing french bread!" << std::endl;
  }
};

class SpanishBakery : public Bakery
{
public:
  Bakery* clone() const override
  {
    std::cout << "Spanish bakery is created!" << std::endl;
    return new SpanishBakery(*this);
  }

  void produce() const override
  {
    std::cout << "Spanish bakery is producing spanish bread!" << std::endl;
  }
};

enum class Nation
{
  France = 0,
  Spain
};

class AbstractNationFactory
{
public:
  static AbstractNationFactory* getInstance(const Nation nation);

  virtual Villager* createVillager() const = 0;
  virtual Bakery* createBakery() const = 0;

private:
  AbstractNationFactory(const AbstractNationFactory&) = delete;
  AbstractNationFactory(AbstractNationFactory&&) = delete;
  AbstractNationFactory& operator=(const AbstractNationFactory&) = delete;

protected:
  AbstractNationFactory() = default;
  ~AbstractNationFactory() = default;
};

class FrancePrototypeFactory : public AbstractNationFactory
{
public:
  static AbstractNationFactory* getInstance()
  {
    static FrancePrototypeFactory factory;
    return &factory;
  }

  Villager* createVillager() const override
  {
    return villager_->clone();
  }

  Bakery* createBakery() const override
  {
    return bakery_->clone();
  }

private:
  FrancePrototypeFactory()
    : villager_(new FrenchVillager())
    , bakery_(new FrenchBakery())
  {
  }

  ~FrancePrototypeFactory()
  {
    delete villager_;
    delete bakery_;
  }

private:
  Villager* villager_;
  Bakery* bakery_;
};

class SpainPrototypeFactory : public AbstractNationFactory
{
public:
  static AbstractNationFactory* getInstance()
  {
    static SpainPrototypeFactory factory;
    return &factory;
  }

  Villager* createVillager() const override
  {
    return villager_->clone();
  }

  Bakery* createBakery() const override
  {
    return bakery_->clone();
  }

private:
  SpainPrototypeFactory()
    : villager_(new SpanishVillager())
    , bakery_(new SpanishBakery())
  {
  }

  ~SpainPrototypeFactory()
  {
    delete villager_;
    delete bakery_;
  }

private:
  Villager* villager_;
  Bakery* bakery_;
};

AbstractNationFactory* AbstractNationFactory::getInstance(const Nation nation)
{
  switch (nation)
  {
  case Nation::France:
    return FrancePrototypeFactory::getInstance();
  case Nation::Spain:
    return SpainPrototypeFactory::getInstance();
  }

  return nullptr;
}

void createColony(const AbstractNationFactory* factory)
{
  Villager* v1 = factory->createVillager();
  Villager* v2 = factory->createVillager();

  v1->action();
  v2->action();

  Bakery* b = factory->createBakery();

  b->produce();
}

int main(int argc, char** argv)
{
  AbstractNationFactory* FranceFactory = AbstractNationFactory::getInstance(Nation::France);
  AbstractNationFactory* SpainFactory = AbstractNationFactory::getInstance(Nation::Spain);

  createColony(FranceFactory);

  std::cout << "\n----------------------------------------------\n\n";

  createColony(SpainFactory);

  std::cout << std::endl;

  return 0;
}