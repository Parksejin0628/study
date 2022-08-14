/*
[10단계 중점 사안]
1. 배열 클래스 BoundCheckAccountPtrArray를 클래스 템플리승로 정의하여 다양한 데이터를 저장할 수 있도록 일반화하기
	- 클래스 템플릿의 이름을 BoundCheckArray로 바꾸기
	- BoundCheckArray.h에 정의하기
	- AccountArray.h와 AccountArray.cpp 삭제하기
*/

#include"BankingCommonDecl.h"
#include"Client.h"
#include"AccountHandler.h"
#include"AccountHandler.h"


int main(void)
{
	int choice;
	AccountHandler accountHandler;

	while (true)
	{
		choice = accountHandler.menu();
		if (choice == funcNum::OPEN)
		{
			accountHandler.openAccount();
		}
		else if (choice == funcNum::DEPOSIT)
		{
			accountHandler.deposit();
		}
		else if (choice == funcNum::WITHDRAW)
		{
			accountHandler.withdraw();
		}
		else if (choice == funcNum::CHECKMONEY)
		{
			accountHandler.checkMoneyOfClients();
		}
		else if (choice == funcNum::EXIT)
		{
			break;
		}
		else
		{
			cout << "잘못된 선택입니다." << endl;
		}
	}
	cin >> choice;

	return 0;
}

