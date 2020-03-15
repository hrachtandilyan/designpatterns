#include "Factories.hh"

LimitedProviderFactory* LimitedProviderFactory::instance_ = nullptr;
UnlimitedProviderFactory* UnlimitedProviderFactory::instance_ = nullptr;

int main(int argc, char** argv)
{
  ProviderFactory* factory = LimitedProviderFactory::getInstance();

  Provider* connectChina = factory->createProviderInstance();

  dynamic_cast<LimitedProvider*>(connectChina)->addBannedWebPage("www.facebook.com");
  connectChina->addCustomer(Customer("192.0.0.123", Location("Armenia", "Yerevan")));

  connectChina->redirect("www.facebook.com");

  return 0;
}
