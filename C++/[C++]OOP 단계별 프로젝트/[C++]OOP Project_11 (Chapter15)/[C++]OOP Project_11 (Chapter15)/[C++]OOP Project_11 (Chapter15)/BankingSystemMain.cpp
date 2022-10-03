/*
[11단계 중점 사안]
다음 두 예외상황에 대한 처리를 작성하기
1. 계좌개설 이후, 예금된 금액보다 더 많은 금액의 출금을 요구하는 예외상황
2. 계좌개설 이후, 입출금 진행 시 프로그램 사용자로부터 0보다 작은 값이 입력되는 예외상황
이 두 상황의 처리를 예외상황 별로 각각 예외 클래스를 정의하기로 하고, 프로그램 사용자에게는 잘못된 입력이 이뤄졌음을 알리고 재 입력을 요구하는 방식으로 예외상황을 처리하자.
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

	return 0;
}

