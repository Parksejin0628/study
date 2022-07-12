#pragma once
#include"BankingCommonDecl.h"
#include"Client.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"

/*
	클래스 이름 : AccountHandler
	클래스 유형 : 컨트롤(Constrol) 클래스
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