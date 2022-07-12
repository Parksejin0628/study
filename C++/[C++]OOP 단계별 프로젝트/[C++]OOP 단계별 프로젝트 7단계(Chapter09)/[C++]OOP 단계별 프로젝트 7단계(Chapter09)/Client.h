#pragma once
#include"BankingCommonDecl.h"

/*
	Ŭ���� �̸� : Client
	Ŭ���� ���� : Emtity Ŭ����
*/


class Client
{
private:
	int accountID;
	char *name;
	int money;

public:
	Client(int accountID, char *name, int money);
	Client(const Client &copy);
	int getMoney() const;
	virtual bool setMoney(int money);
	void showClientInfo() const;
	bool checkID(int ID) const;
	~Client();
};