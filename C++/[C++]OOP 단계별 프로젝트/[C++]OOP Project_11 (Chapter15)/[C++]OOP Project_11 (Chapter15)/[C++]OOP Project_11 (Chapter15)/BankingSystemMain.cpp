/*
[11�ܰ� ���� ���]
���� �� ���ܻ�Ȳ�� ���� ó���� �ۼ��ϱ�
1. ���°��� ����, ���ݵ� �ݾ׺��� �� ���� �ݾ��� ����� �䱸�ϴ� ���ܻ�Ȳ
2. ���°��� ����, ����� ���� �� ���α׷� ����ڷκ��� 0���� ���� ���� �ԷµǴ� ���ܻ�Ȳ
�� �� ��Ȳ�� ó���� ���ܻ�Ȳ ���� ���� ���� Ŭ������ �����ϱ�� �ϰ�, ���α׷� ����ڿ��Դ� �߸��� �Է��� �̷������� �˸��� �� �Է��� �䱸�ϴ� ������� ���ܻ�Ȳ�� ó������.
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

	return 0;
}

