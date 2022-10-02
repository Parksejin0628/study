#pragma once
#include"AccountException.h"

class AccountException_underZero : public AccountException
{
	virtual int reInput()
	{
		int input = -1;
		while (input < 0)
		{
			printMessage();
			cin >> input;
		}
		return input;
	}
	virtual void printMessage()
	{
		cout << "0보다 작은 수를 입력하였습니다." << endl;
		cout << "다시 입력해주세요 : ";
	}
};