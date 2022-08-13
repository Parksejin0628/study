#pragma once
#include"BankingCommonDecl.h"
#include"String.h"

/*
	클래스 이름 : Client
	클래스 유형 : Emtity 클래스
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