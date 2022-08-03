#pragma once
#include"Client.h"

class NormalAccount : public Client
{
private:
	int interestRate;
public:
	NormalAccount(int iID, char* iName, int iMoney, int iInterestRate);
	virtual bool setMoney(int money);
};