#pragma once

#include <string>

struct Location
{
  Location(const std::string& pCountry, const std::string& pCity)
    : country(pCountry)
    , city(pCity)
  {}

  std::string country;
  std::string city;
};

struct Customer
{
  Customer(const std::string& pIpAddress, const Location& pLocation)
    : ipAddress(pIpAddress)
    , location(pLocation)
  {}

  bool operator<(const Customer& other) const {
    return ipAddress < other.ipAddress;
  }

  std::string ipAddress;
  Location location;
};

class Provider
{
public:
  virtual int redirect(const std::string& webPage) = 0;
  virtual int addCustomer(const Customer& customer) = 0;
  virtual int removeCustomer(const Customer& customer) = 0;
  virtual Location getCustomerLocation(const Customer& customer) = 0;
};