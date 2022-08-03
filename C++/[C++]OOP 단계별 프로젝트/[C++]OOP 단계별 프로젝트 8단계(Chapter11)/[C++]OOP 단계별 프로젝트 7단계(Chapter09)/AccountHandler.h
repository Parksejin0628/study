/*
�����̸� : AccountHandler.h
�ۼ��� : �ڼ���
������Ʈ ���� : [22-08-03]
*/


#pragma once
#include"BankingCommonDecl.h"
#include"Client.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"BoundCheckClientPtrArray.h"



class AccountHandler
{
private:
	BoundCheckClientPtrArray accArr;
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