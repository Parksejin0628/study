/*
[6단계 중점 사안]
1. Account 클래스를 상속하는 NormalAccount, HighCreditAccount 계좌 추가 정의
 > NormalAccount(보통예금계좌) : 평범하게 이자를 지급하는 계좌이다.
 > HighCreditAccount(신용신뢰계좌) : 신용도에 따라 추가로 이자를 지급하는 계좌이다.
2. 보통예금계좌에서 이율정보(이자를 얼마나 할 것인지)를 등록할 수 있도록 정의하자.
3. 신용신뢰계좌에는 다음과 같은 특성을 추가로 부여한다.
 > NormalAccount 클래스와 마찬가지로 객체 생성과정에서 기본이율을 등록할 수 있다.
 > 고객의 신용등급을 A, B, C로 나누고 계좌개설 시 이 정보를 등록한다.
 > A, B, C 등급별로 각각 기본이율에 7%, 4%, 2% 이율을 추가로 제공한다.
4. 이자는 편의상 입금 시에 이자가 원금에 더해지는 방식으로 간주한다.
 > 단, 계좌개설 과정에서 초기 입금되는 금액은 이자를 계산하지 않는다.
 > 계좌개설 후 별도의 입금과정을 거칠 때에만 이자가 발생하는 것으로 간주한다.
 > 이자의 계산과정에서 발생하는 소수점 이하의 금액은 무시한다.
5. AccountHandler 클래스에서 메뉴의 선택, 데이터의 입력과정 변경을 제외하고 큰 변화가 없어야 한다.
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

