#pragma once

#include "ProviderInterface.hh"
#include <iostream>
#include <set>

class LimitedProvider : public Provider
{
public:
  virtual int redirect(const std::string& webPage) {
    if (bannedWebPages_.find(webPage) != bannedWebPages_.end()) {
      std::cout << "Web page " << webPage << " is banned by your Internet Service Provider." << std::endl;
      return 1;
    }
    std::cout << "Redirecting to " << webPage << " in background mode.\n";
    return 0;
  }

  virtual int addCustomer(const Customer& customer) {
    auto it = customers_.insert(customer);
    if (it.second == true) {
      std::cout << "Customer with IP address " << customer.ipAddress << " now is conected to our services." << std::endl;
      return 0;
    }
    std::cout << "Customer with IP address " << customer.ipAddress << " already uses our services." << std::endl;
    return 1;
  }

  virtual int removeCustomer(const Customer& customer) {
    int removedNum = customers_.erase(customer);
    if (removedNum > 0) {
      std::cout << "Customer with IP address " << customer.ipAddress << " left our services." << std::endl;
      return 0;
    }
    std::cout << "There is no such customer with IP address " << customer.ipAddress << " in out customer list." << std::endl;
    return 1;
  }

  virtual int addBannedWebPage(const std::string& webPage) {
    auto it = bannedWebPages_.insert(webPage);
    if (it.second == false) {
      std::cout << webPage  << " is already banned for our users." << std::endl;
      return 1;
    }
    std::cout << webPage << " is now banned for our users." << std::endl;
    return 0;
  }

  virtual int removeBannedWebPage(const std::string& webPage) {
    int removedNum = bannedWebPages_.erase(webPage);
    if (removedNum > 0) {
      std::cout << "Web page " << webPage << " is removed from the banned web pages list. Users now can access that web page." << std::endl;
      return 0;
    }
    std::cout << "There is no such web page in our banned web pages list. Users can access that web page." << std::endl;
    return 1;
  }

  virtual Location getCustomerLocation(const Customer& customer) {
    return customer.location;
  }
  
private:
  std::set<Customer> customers_;
  std::set<std::string> bannedWebPages_;
};

class UnlimitedProvider : public Provider
{
public:
  virtual int redirect(const std::string& webPage) {
    std::cout << "Redirecting to " << webPage << " in background mode.\n";
    return 0;
  }

  virtual int addCustomer(const Customer& customer) {
    auto it = customers_.insert(customer);
    if (it.second == true) {
      std::cout << "Customer with IP address " << customer.ipAddress << " now is conected to our services." << std::endl;
      return 0;
    }
    std::cout << "Customer with IP address " << customer.ipAddress << " already uses our services." << std::endl;
    return 1;
  }

  virtual int removeCustomer(const Customer& customer) {
    int removedNum = customers_.erase(customer);
    if (removedNum > 0) {
      std::cout << "Customer with IP address " << customer.ipAddress << " left our services." << std::endl;
      return 0;
    }
    std::cout << "There is no such customer with IP address " << customer.ipAddress << " in our customer list." << std::endl;
    return 1;
  }

  virtual Location getCustomerLocation(const Customer& customer) {
    return customer.location;
  }

private:
  std::set<Customer> customers_;

};