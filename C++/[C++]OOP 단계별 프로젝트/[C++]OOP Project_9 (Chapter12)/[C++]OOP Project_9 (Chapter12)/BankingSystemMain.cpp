/*
[8�ܰ� ���� ���]
1. Client Ŭ������ ���� ���縦 �ϴ� ���� ������ ����
2. AccountHandler Ŭ������ �迭 ��� ������ �迭 Ŭ������ ��ü
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

