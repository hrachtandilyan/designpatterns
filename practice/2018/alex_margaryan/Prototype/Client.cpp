#include "Client.h"
#include "FacebookAccount.h"
#include "GoogleAccount.h"
#include "YoutubeAccount.h"

Account* Client::prototypes[3] = { new FacebookAccount, new GoogleAccount, new YoutubeAccount };

Account* Client::makeAccount(std::string accountName)
{
	if (accountName == "facebook")
		return prototypes[0]->clone();
	if (accountName == "google")
		return prototypes[1]->clone();
	if (accountName == "youtube")
		return prototypes[2]->clone();
	return 0;
}