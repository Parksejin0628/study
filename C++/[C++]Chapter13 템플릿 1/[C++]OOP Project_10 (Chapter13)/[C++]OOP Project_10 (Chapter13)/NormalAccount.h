#pragma once
#include"Client.h"

class NormalAccount : public Client
{
private:
	int interestRate;
public:
	NormalAccount(int iID, String iName, int iMoney, int iInterestRate);
	virtual bool setMoney(int money);
};