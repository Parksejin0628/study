/*
[8단계 중점 사안]
1. Client 클래스에 깊은 복사를 하는 대입 연산자 정의
2. AccountHandler 클래스의 배열 멤버 변수를 배열 클래스로 대체
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

