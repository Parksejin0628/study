/*
[10�ܰ� ���� ���]
1. �迭 Ŭ���� BoundCheckAccountPtrArray�� Ŭ���� ���ø��·� �����Ͽ� �پ��� �����͸� ������ �� �ֵ��� �Ϲ�ȭ�ϱ�
	- Ŭ���� ���ø��� �̸��� BoundCheckArray�� �ٲٱ�
	- BoundCheckArray.h�� �����ϱ�
	- AccountArray.h�� AccountArray.cpp �����ϱ�
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
			cout << "�߸��� �����Դϴ�." << endl;
		}
	}
	cin >> choice;

	return 0;
}

