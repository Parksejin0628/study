/*
파일이름 : AccountHandler.cpp
작성자 : 박세진
업데이트 정보 : [22-08-03]
*/



#include"AccountHandler.h"


AccountHandler::AccountHandler() : clientIndex(0), accArr(100)
{

}
int AccountHandler::menu() const
{
	int choice;

	cout << endl << "----------------Menu-----------------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
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
	cout << "[계좌종류 선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> choice;

	cout << "개설할 계좌 번호 : ";
	cin >> accountID;
	cout << "고객의 이름 : ";
	cin >> name;
	cout << "입금할 금액 : ";
	cin >> money;
	cout << "이자율 : ";
	cin >> interestRate;
	//Normal
	if (choice == funcNum::NORMAL)
	{
		accArr[clientIndex] = new NormalAccount(accountID, name, money, interestRate);

	}
	else if (choice == funcNum::CREDIT)
	{
		cout << "신용등급(1toA, 2toB, 3toC): ";
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

	cout << "성공적으로 개설되었습니다!" << endl;

	return;
}
void AccountHandler::deposit()
{
	int input = 0;
	int index = 0;

	cout << "[입 금]" << endl;
	while (true)
	{
		cout << "입금할 계좌 번호 : ";
		cin >> input;
		index = searchID(input);
		if (index == -1)
		{
			cout << "없는 계좌 번호입니다. 다시 입력해 주십시오." << endl;
			continue;
		}
		break;
	}
	cout << "입금할 금액 : ";
	cin >> input;
	accArr[index]->setMoney(input);
	cout << "성공적으로 처리되었습니다." << endl;

	return;
}
void AccountHandler::withdraw()
{
	int input = 0;
	int index = 0;

	cout << "[출 금]" << endl;
	while (true)
	{
		cout << "출금할 계좌 번호 : ";
		cin >> input;
		index = searchID(input);
		if (index == -1)
		{
			cout << "없는 계좌 번호입니다. 다시 입력해 주십시오." << endl;
			continue;
		}
		break;
	}
	while (true)
	{
		cout << "입금할 금액 : ";
		cin >> input;
		if (!accArr[index]->setMoney(-input))
		{
			cout << "잔액보다 큰 금액입니다. 다시 입력해 주십시오." << endl;
			continue;
		}
		break;
	}
	cout << "성공적으로 처리되었습니다." << endl;

	return;
}
void AccountHandler::checkMoneyOfClients() const
{
	cout << "[계좌정보 전체 출력]" << endl;
	for (int i = 0; i < clientIndex; i++)
	{
		accArr[i]->showClientInfo();
	}
	cout << "모든 정보가 출력되었습니다." << endl;

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