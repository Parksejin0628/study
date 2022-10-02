#pragma once

#include"AccountException.h"

class AccountException_moremoney : public AccountException
{
private:
	int crit;
public:
	AccountException_moremoney(int criterion) : crit(criterion) { }
	virtual int reInput()
	{
		int input = crit + 1;
		while (input > crit)
		{
			printMessage();
			cin >> input;
		}
		return input;
	}
	virtual void printMessage()
	{
		cout << "보유 금액보다 큰 수를 입력하였습니다." << endl;
		cout << "다시 입력해주세요 : ";
	}
};