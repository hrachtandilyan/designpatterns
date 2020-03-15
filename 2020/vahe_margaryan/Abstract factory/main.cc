#include "Factories.hh"

LimitedProviderFactory* LimitedProviderFactory::instance_ = nullptr;
UnlimitedProviderFactory* UnlimitedProviderFactory::instance_ = nullptr;

int main(int argc, char** argv)
{
  ProviderFactory* factory = LimitedProviderFactory::getInstance();

  Provider* conectChina = factory->createProviderInstance();

  dynamic_cast<LimitedProvider*>(conectChina)->addBannedWebPage("www.facebook.com");
  conectChina->addCustomer(Customer("192.0.0.123", Location("Armenia", "Yerevan")));

  conectChina->redirect("www.facebook.com");

  return 0;
}