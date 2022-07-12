#pragma once
#include"BankingCommonDecl.h"
#include"Client.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"

/*
	Ŭ���� �̸� : AccountHandler
	Ŭ���� ���� : ��Ʈ��(Constrol) Ŭ����
*/

class AccountHandler
{
private:
	Client *clients[100];
	int clientIndex;
public:
	AccountHandler();
	int menu() const;
	void openAccount();
	void deposit();
	void withdraw();
	void checkMoneyOfClients() const;
	int searchID(int number) const;
	~AccountHandler();
};