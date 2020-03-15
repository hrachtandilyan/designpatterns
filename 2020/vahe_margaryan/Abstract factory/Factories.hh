#pragma once

#include "Providers.hh"

class ProviderFactory
{
public:
  virtual Provider* createProviderInstance() = 0;

protected:
  ProviderFactory() {};

};

class LimitedProviderFactory : public ProviderFactory
{
public:
  static ProviderFactory* getInstance() {
    if (instance_ == nullptr) {
      return new LimitedProviderFactory();
    }
    return instance_;
  }

  virtual Provider* createProviderInstance() {
    return new LimitedProvider();
  }

private:
  static LimitedProviderFactory* instance_;
};

class UnlimitedProviderFactory : public ProviderFactory
{
public:
  static ProviderFactory* getInstance() {
    if (instance_ == nullptr) {
      return new UnlimitedProviderFactory();
    }
    return instance_;
  }

  virtual Provider* createProviderInstance() {
    return new UnlimitedProvider();
  }

private:
  static UnlimitedProviderFactory* instance_;
  
};