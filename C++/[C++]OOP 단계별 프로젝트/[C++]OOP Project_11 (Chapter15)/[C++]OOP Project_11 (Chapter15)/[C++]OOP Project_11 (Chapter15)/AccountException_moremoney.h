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
		cout << "���� �ݾ׺��� ū ���� �Է��Ͽ����ϴ�." << endl;
		cout << "�ٽ� �Է����ּ��� : ";
	}
};