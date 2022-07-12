#pragma once
#include"BankingCommonDecl.h"

/*
	클래스 이름 : Client
	클래스 유형 : Emtity 클래스
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