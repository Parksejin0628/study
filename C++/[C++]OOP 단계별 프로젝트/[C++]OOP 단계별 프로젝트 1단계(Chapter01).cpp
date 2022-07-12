#include<iostream>
#pragma warning(disable:4996)

//using namespace std;
using std::cin;
using std::cout;
using std::endl;
const int NAME_LEN = 20;

int menu();
void openAccount();
void deposit();
void withdraw();
void checkMoneyOfClients();
int searchID(int number);

typedef struct Client
{
	int accountNumber;
	int money;
	char name[NAME_LEN]; 
}client;

enum { OPEN = 1, DEPOSIT, WITHDRAW, CHECKMONEY, EXIT };

client clients[100]; 
int clientIndex = 0; 

int main(void)
{
	int choice;
	
	while(true)
	{
		choice = menu();
		if(choice == OPEN)
		{
			openAccount();
		}
		else if(choice == DEPOSIT)
		{
			deposit();
		}
		else if(choice == WITHDRAW)
		{
			withdraw();
		}
		else if(choice == CHECKMONEY)
		{
			checkMoneyOfClients();
		}
		else if(choice == EXIT)
		{
			break;
		}
		else
		{
			cout<<"잘못된 선택입니다."<<endl; 
		}
	}
	cin>>choice;
	
	return 0;
}

int menu()
{
	int choice;
	
	cout<<endl<<"----------------Menu-----------------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	cout<<"선택: ";
	cin>>choice;
	cout<<endl;
	
	return choice;
}

void openAccount()
{
	cout<<"[계좌개설]"<<endl; 
	cout<<"개설할 계좌 번호 : ";
	cin>>clients[clientIndex].accountNumber;
	cout<<"고객의 이름 : ";
	cin>>clients[clientIndex].name;
	cout<<"입금할 금액 : ";
	cin>>clients[clientIndex].money;
	cout<<"성공적으로 개설되었습니다!"<<endl; 
	clientIndex++;
	
	return;
}

void deposit()
{
	int input = 0;
	int index = 0;
	
	cout<<"[입 금]"<<endl;
	while(true)
	{
		cout<<"입금할 계좌 번호 : ";
		cin>>input;
		index = searchID(input);
		if(index == -1)
		{
			cout<<"없는 계좌 번호입니다. 다시 입력해 주십시오."<<endl;
			continue;
		}
		break;
	}
	cout<<"입금할 금액 : ";
	cin>>input;
	clients[index].money += input;
	cout<<"성공적으로 처리되었습니다."<<endl;
	
	return;
}

void withdraw()
{
	int input = 0;
	int index = 0;
	
	cout<<"[출 금]"<<endl;
	while(true)
	{
		cout<<"출금할 계좌 번호 : ";
		cin>>input;
		index = searchID(input);
		if(index == -1)
		{
			cout<<"없는 계좌 번호입니다. 다시 입력해 주십시오."<<endl;
			continue;
		}
		break;
	}
	while(true)
	{
		cout<<"입금할 금액 : ";
		cin>>input;
		if(input > clients[index].money)
		{
			cout<<"잔액보다 큰 금액입니다. 다시 입력해 주십시오."<<endl;
			continue;
		}
		break;
	} 
	
	clients[index].money -= input;
	cout<<"성공적으로 처리되었습니다."<<endl;
	
	return;
}
void checkMoneyOfClients()
{
	cout<<"[계좌정보 전체 출력]"<<endl; 
	for(int i=0; i<clientIndex; i++)
	{
		cout<<"계좌번호 : "<<clients[i].accountNumber<<endl;
		cout<<"이름 : "<<clients[i].name<<endl;
		cout<<"잔액 : "<<clients[i].money<<endl<<endl;
	}
	cout<<"모든 정보가 출력되었습니다."<<endl;
	
	return; 
}

int searchID(int number)
{
	for(int i=0; i<clientIndex; i++)
	{
		if(clients[i].accountNumber == number)
		{
			return i;
		}
	}
	
	return -1;
}

/*
기능 1. 계좌개설
 - 개설할 계좌번호, 이름, 입금액을 입력한다.
 - 입력한 내용으로 계좌정보를 등록한다. 
기능 2. 입금
 - 작업할 계좌번호를 입력한다.
 - 입금하고자 하는 금액을 입력한다.
 - 입금한 금액을 더해서 데이터를 수정한다. 
기능 3. 출금
 - 작업할 계좌번호를 입력한다.
 - 출금하고자 하는 금액을 입력한다.
 - 출금금액이 보유 잔액보다 큰 경우 재입력한다.
 - 출금금액이 보유 잔액보다 작은 경우 출금한 금액을 빼서 데이터를 수정한다. 
기능 4. 전체고객 잔액조회
 - 모든 고객의 정보를 출력한다. 

[가정]
1. 계좌번호 중복 X (중복검사를 하지 않는다.)
2. 입금, 출금은 0보다 크다. (입금, 출금액 오류검사 X)
3. 고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액만 저장 및 관리한다.
4. 둘 이상의 고객 정보 저장을 위해 배열 사용한다.
5. 계좌번호는 정수형태이다.  
*/
