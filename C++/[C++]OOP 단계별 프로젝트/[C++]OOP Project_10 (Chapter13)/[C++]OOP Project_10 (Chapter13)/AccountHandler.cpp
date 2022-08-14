/*
�����̸� : AccountHandler.cpp
�ۼ��� : �ڼ���
������Ʈ ���� : [22-08-03]
*/



#include"AccountHandler.h"


AccountHandler::AccountHandler() : clientIndex(0), accArr(100)
{

}
int AccountHandler::menu() const
{
	int choice;

	cout << endl << "----------------Menu-----------------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
	cin >> choice;
	cout << endl;

	return choice;
}

void AccountHandler::openAccount()
{
	int accountID;
	String name;
	int money;
	int interestRate;
	int credit;
	funcNum::creditInfo creditRating;
	int choice = 0;
	cout << "[�������� ����]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> choice;

	cout << "������ ���� ��ȣ : ";
	cin >> accountID;
	cout << "���� �̸� : ";
	cin >> name;
	cout << "�Ա��� �ݾ� : ";
	cin >> money;
	cout << "������ : ";
	cin >> interestRate;
	//Normal
	if (choice == funcNum::NORMAL)
	{
		accArr[clientIndex] = new NormalAccount(accountID, name, money, interestRate);

	}
	else if (choice == funcNum::CREDIT)
	{
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> credit;
		if (credit == 1)
		{
			creditRating = funcNum::CREDIT_A;
		}
		else if (credit == 2)
		{
			creditRating = funcNum::CREDIT_B;
		}
		else if (credit == 3)
		{
			creditRating = funcNum::CREDIT_C;
		}
		accArr[clientIndex] = new HighCreditAccount(accountID, name, money, interestRate, creditRating);
	}
	clientIndex++;

	cout << "���������� �����Ǿ����ϴ�!" << endl;

	return;
}
void AccountHandler::deposit()
{
	int input = 0;
	int index = 0;

	cout << "[�� ��]" << endl;
	while (true)
	{
		cout << "�Ա��� ���� ��ȣ : ";
		cin >> input;
		index = searchID(input);
		if (index == -1)
		{
			cout << "���� ���� ��ȣ�Դϴ�. �ٽ� �Է��� �ֽʽÿ�." << endl;
			continue;
		}
		break;
	}
	cout << "�Ա��� �ݾ� : ";
	cin >> input;
	accArr[index]->setMoney(input);
	cout << "���������� ó���Ǿ����ϴ�." << endl;

	return;
}
void AccountHandler::withdraw()
{
	int input = 0;
	int index = 0;

	cout << "[�� ��]" << endl;
	while (true)
	{
		cout << "����� ���� ��ȣ : ";
		cin >> input;
		index = searchID(input);
		if (index == -1)
		{
			cout << "���� ���� ��ȣ�Դϴ�. �ٽ� �Է��� �ֽʽÿ�." << endl;
			continue;
		}
		break;
	}
	while (true)
	{
		cout << "�Ա��� �ݾ� : ";
		cin >> input;
		if (!accArr[index]->setMoney(-input))
		{
			cout << "�ܾ׺��� ū �ݾ��Դϴ�. �ٽ� �Է��� �ֽʽÿ�." << endl;
			continue;
		}
		break;
	}
	cout << "���������� ó���Ǿ����ϴ�." << endl;

	return;
}
void AccountHandler::checkMoneyOfClients() const
{
	cout << "[�������� ��ü ���]" << endl;
	for (int i = 0; i < clientIndex; i++)
	{
		accArr[i]->showClientInfo();
	}
	cout << "��� ������ ��µǾ����ϴ�." << endl;

	return;
}
int AccountHandler::searchID(int number) const
{
	for (int i = 0; i < clientIndex; i++)
	{
		if (accArr[i]->checkID(number))
		{
			return i;
		}
	}

	return -1;
}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < clientIndex; i++)
	{
		delete accArr[i];
	}
}