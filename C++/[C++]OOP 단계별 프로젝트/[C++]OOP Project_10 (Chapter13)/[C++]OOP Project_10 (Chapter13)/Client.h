#pragma once
#include"BankingCommonDecl.h"
#include"String.h"

/*
	Ŭ���� �̸� : Client
	Ŭ���� ���� : Emtity Ŭ����
*/


class Client
{
private:
	int accountID;
	String name;
	int money;

public:
	Client(int accountID, String name, int money);
	Client(const Client &copy);
	int getMoney() const;
	virtual bool setMoney(int money);
	void showClientInfo() const;
	bool checkID(int ID) const;
	Client& operator=(Client& ref);
	~Client();
};