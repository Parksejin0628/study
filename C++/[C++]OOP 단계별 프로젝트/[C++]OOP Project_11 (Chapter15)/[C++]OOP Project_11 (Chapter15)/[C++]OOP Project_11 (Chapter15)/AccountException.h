#pragma once

#include"BankingCommonDecl.h"

class AccountException
{
public:
	AccountException() {	}
	virtual int reInput()
	{
		return 0;
	}
	virtual void printMessage()	{	}
};