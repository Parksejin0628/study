#pragma once
#include"NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	funcNum::creditInfo credit;
public:
	HighCreditAccount(int ID, char *name, int money, int interestRate, funcNum::creditInfo credit);
};

