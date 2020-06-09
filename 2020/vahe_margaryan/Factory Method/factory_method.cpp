#include <iostream>
#include <vector>

class Transport
{
public:
  Transport()
  {
    count_++;
  }

  virtual void deliver() const = 0;

  virtual ~Transport()
  {
  }

protected:
  static unsigned count_;
};

unsigned Transport::count_ = 0;

class Truck : public Transport
{
public:
  Truck()
    : id_(count_)
  {
  }

  void deliver() const override
  {
    std::cout << "Truck (ID: " << id_ << ") is on its way!" << std::endl;
  }

private:
  unsigned id_;
};

class Ship : public Transport
{
public:
  Ship()
    : id_(count_)
  {
  }

  void deliver() const override
  {
    std::cout << "Ship (ID: " << id_ << ") is on its way!" << std::endl;
  }

private:
  unsigned id_;
};

class TransportFactory
{
public:
  virtual Transport* create() const = 0;
};

class TruckFactory : public TransportFactory
{
public:
  Transport* create() const override
  {
    return new Truck();
  }
};

class ShipFactory : public TransportFactory
{
public:
  Transport* create() const override
  {
    return new Ship();
  }
};

enum class TransportType
{
  Truck = 0,
  Ship = 1
};

class DeliveryService
{
public:
  DeliveryService()
    : truckFactory_(new TruckFactory())
    , shipFactory_(new ShipFactory())
  {}

  void addTransport(const TransportType& type)
  {
    switch (type)
    {
    case TransportType::Truck:
      transports_.push_back(truckFactory_->create());
      break;
    case TransportType::Ship:
      transports_.push_back(shipFactory_->create());
      break;
    default:
      break;
    }
  }

  void makeDeliveries() const
  {
    for (const Transport* transport : transports_)
    {
      transport->deliver();
    }
  }

private:
  TransportFactory* truckFactory_;
  TransportFactory* shipFactory_;

  std::vector<Transport*> transports_;
};

int main(int argc, char** argv)
{
  DeliveryService service;

  service.addTransport(TransportType::Truck);
  service.addTransport(TransportType::Truck);
  service.addTransport(TransportType::Ship);
  service.addTransport(TransportType::Ship);
  service.addTransport(TransportType::Truck);
  service.addTransport(TransportType::Truck);
  service.addTransport(TransportType::Ship);
  service.addTransport(TransportType::Ship);
  service.addTransport(TransportType::Ship);
  service.addTransport(TransportType::Truck);

  service.makeDeliveries();

  return 0;
}