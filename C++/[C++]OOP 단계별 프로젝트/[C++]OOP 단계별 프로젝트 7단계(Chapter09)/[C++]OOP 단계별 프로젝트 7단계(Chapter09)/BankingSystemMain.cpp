/*
[6�ܰ� ���� ���]
1. Account Ŭ������ ����ϴ� NormalAccount, HighCreditAccount ���� �߰� ����
 > NormalAccount(���뿹�ݰ���) : ����ϰ� ���ڸ� �����ϴ� �����̴�.
 > HighCreditAccount(�ſ�ŷڰ���) : �ſ뵵�� ���� �߰��� ���ڸ� �����ϴ� �����̴�.
2. ���뿹�ݰ��¿��� ��������(���ڸ� �󸶳� �� ������)�� ����� �� �ֵ��� ��������.
3. �ſ�ŷڰ��¿��� ������ ���� Ư���� �߰��� �ο��Ѵ�.
 > NormalAccount Ŭ������ ���������� ��ü ������������ �⺻������ ����� �� �ִ�.
 > ���� �ſ����� A, B, C�� ������ ���°��� �� �� ������ ����Ѵ�.
 > A, B, C ��޺��� ���� �⺻������ 7%, 4%, 2% ������ �߰��� �����Ѵ�.
4. ���ڴ� ���ǻ� �Ա� �ÿ� ���ڰ� ���ݿ� �������� ������� �����Ѵ�.
 > ��, ���°��� �������� �ʱ� �ԱݵǴ� �ݾ��� ���ڸ� ������� �ʴ´�.
 > ���°��� �� ������ �Աݰ����� ��ĥ ������ ���ڰ� �߻��ϴ� ������ �����Ѵ�.
 > ������ ���������� �߻��ϴ� �Ҽ��� ������ �ݾ��� �����Ѵ�.
5. AccountHandler Ŭ�������� �޴��� ����, �������� �Է°��� ������ �����ϰ� ū ��ȭ�� ����� �Ѵ�.
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

