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
		cout << "0���� ���� ���� �Է��Ͽ����ϴ�." << endl;
		cout << "�ٽ� �Է����ּ��� : ";
	}
};