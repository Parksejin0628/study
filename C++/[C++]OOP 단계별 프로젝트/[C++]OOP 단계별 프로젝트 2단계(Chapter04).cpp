/*
[2단계 중점 사안]
1. 구조체 Account를 클래스 Account로 변경한다. 이 때 정보은닉, 캡슐화, 생성자, 소멸자를 고민하도록 하자
2. Account 클래스에서 고객의 이름을 저장할 때 동적 할당의 형태로 구현하자.(배열이 아닌 char 포인터)
3. 객체 배열을 선언하지 말고, 객체 포인터 배열을 선언하자. 
*/

#include<iostream>
#include<cstring>

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

/*typedef struct Client
{
	int accountNumber;
	int money;
	char name[NAME_LEN]; 
}client;*/

namespace Client_h
{
	//client.h
	namespace funcNum
	{
		enum { OPEN = 1, DEPOSIT, WITHDRAW, CHECKMONEY, EXIT };
	}

	class Client
	{
	private:
		int accountID;
		char *name;
		int money;
	public:
		Client(int accountID, char *name, int money);
		bool setMoney(int money);
		void showClientInfo() const;
		bool checkID(int ID) const;
		~Client();
	};
	
	//client.cpp
	//Client
	Client::Client(int accountID, char *name, int money) : accountID(accountID), money(money)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	bool Client::setMoney(int money)
	{
		if(this->money + money < 0)
		{
			return false;
		}
		this->money += money; 
		return true;
	}
	void Client::showClientInfo() const
	{
		cout<<"계좌번호 : "<<accountID<<endl;
		cout<<"이름 : "<<name<<endl;
		cout<<"잔액 : "<<money<<endl<<endl;
		
		return;
	}
	bool Client::checkID(int ID) const
	{
		if(ID == accountID)
		{
			return true;
		}
		return false;
	}
	Client::~Client()
	{
		delete []name;
	}
}

using namespace Client_h; //#include"client.h"

Client *clients[100]; 
int clientIndex = 0; 

int main(void)
{
	int choice;
	
	while(true)
	{
		choice = menu();
		if(choice == funcNum::OPEN)
		{
			openAccount();
		}
		else if(choice == funcNum::DEPOSIT)
		{
			deposit();
		}
		else if(choice == funcNum::WITHDRAW)
		{
			withdraw();
		}
		else if(choice == funcNum::CHECKMONEY)
		{
			checkMoneyOfClients();
		}
		else if(choice == funcNum::EXIT)
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

// 메뉴창 띄우기 
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

//계좌 생성 화면 및 기능 
void openAccount()
{
	int accountID;
	char name[30];
	int money;
	cout<<"[계좌개설]"<<endl; 
	cout<<"개설할 계좌 번호 : ";
	cin>>accountID;
	cout<<"고객의 이름 : ";
	cin>>name;
	cout<<"입금할 금액 : ";
	cin>>money;
	
	clients[clientIndex] = new Client(accountID, name, money);
	clientIndex++;
	
	cout<<"성공적으로 개설되었습니다!"<<endl; 
	
	return;
}

//입금부터 함수 재정리 
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
	clients[index].setMoney(input);
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
		if(!clients[index].setMoney(-input))
		{
			cout<<"잔액보다 큰 금액입니다. 다시 입력해 주십시오."<<endl;
			continue;
		}
		break;
	} 
	cout<<"성공적으로 처리되었습니다."<<endl;
	
	return;
}
void checkMoneyOfClients()
{
	cout<<"[계좌정보 전체 출력]"<<endl; 
	for(int i=0; i<clientIndex; i++)
	{
		clients[i].showClientInfo();
	}
	cout<<"모든 정보가 출력되었습니다."<<endl;
	
	return; 
}

int searchID(int number)
{
	for(int i=0; i<clientIndex; i++)
	{
		if(clients[i].checkID(number))
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

[Client 객체]
1. 계좌를 개설할 때 생성자를 이용한다.
2. 입금, 출금, 잔액 조회를 멤버함수로 진행한다. 
*/
