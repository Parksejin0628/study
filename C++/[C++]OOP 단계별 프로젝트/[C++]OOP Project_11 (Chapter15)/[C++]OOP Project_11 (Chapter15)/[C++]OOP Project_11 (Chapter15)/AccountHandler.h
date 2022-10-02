/*
파일이름 : AccountHandler.h
작성자 : 박세진
업데이트 정보 : [22-08-03]
*/


#pragma once
#include"BankingCommonDecl.h"
#include"Client.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"BoundCheckArray.h"
#include"String.h"
#include"AccountException.h"
#include"AccountException_moremoney.h"
#include"AccountException_underZero.h"



class AccountHandler
{
private:
	BoundCheckArray<Client*> accArr;
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