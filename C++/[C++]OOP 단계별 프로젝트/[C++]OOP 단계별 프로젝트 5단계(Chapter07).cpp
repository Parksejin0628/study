/*
[5단계 중점 사안]
1. Banking System의 주요기능을 담당하는 컨트롤 클래스를 구현한다.
2. AccountHandler 라는 일므의 컨트롤 클래스를 정의하고, 앞서 정의한 전역함수들을 이 클래스의 멤버함수에 포함시킨다.
3. Account 객체의 저장을 위해 선언한 배열과 변수도 이 클래스의 멤버에 포함시킨다.
4. AccountHandler 클래스 기반으로 프로그램이 실행되도록 main 함수를 변경한다.

<컨트롤 클래스>
1. 컨트롤 클래스의 특징은 다음과 같다.
	- 프로그램 전체의 기능을 담당한다. 따라서, 기능적 성격이 강한 클래스이다.
	- 컨트롤 클래스만 봐도 프로그램의 전체 기능과 흐름을 파악할 수 있다.
2. 컨트롤 클래스를 제외한 대부분의 클래스는 Entity 클래스라고 한다.
	- 데이터적 성격이 강하다. 따라서 파일 및 데이터 베이스에 저장되는 데이터를 소유하고 있다.
	- 프로그램의 기능을 파악하는데 도움을 주지는 못한다.
	- 그러나 프로그램상에서 관리되는 데이터의 종류를 파악하는 데는 도움이 된다. 
*/

#include<iostream>
#include<cstring>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;
const int NAME_LEN = 20;

/*
int menu();
void openAccount();
void deposit();
void withdraw();
void checkMoneyOfClients();
int searchID(int number);
*/

/*typedef struct Client 
{
	int accountNumber;
	int money;
	char name[NAME_LEN]; 
}client;*/

/*
	클래스 이름 : Client
	클래스 유형 : Emtity 클래스
*/
 

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
		Client(const Client &copy);
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
	Client::Client(const Client &copy) : accountID(copy.accountID), money(copy.money)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
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

/*
	클래스 이름 : AccountHandler
	클래스 유형 : 컨트롤(Constrol) 클래스
*/ 

namespace AccountHandler_h
{
	//AccountHandler.h
	class AccountHandler
	{
	private:
		Client *clients[100];
		int clientIndex;
	public:
		AccountHandler();
		int menu() const;
		void openAccount();
		void deposit();
		void withdraw();
		void checkMoneyOfClients() const;
		int searchID(int number) const;
		~AccountHandler();
	};
	
	//AccountHandler.cpp
	AccountHandler::AccountHandler() : clientIndex(0)
	{
		
	}
	int AccountHandler::menu() const
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
	
	void AccountHandler::openAccount()
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
	void AccountHandler::deposit()
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
		clients[index]->setMoney(input);
		cout<<"성공적으로 처리되었습니다."<<endl;
	
		return;
	}
	void AccountHandler::withdraw()
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
			if(!clients[index]->setMoney(-input))
			{
				cout<<"잔액보다 큰 금액입니다. 다시 입력해 주십시오."<<endl;
				continue;
			}
			break;
		} 
		cout<<"성공적으로 처리되었습니다."<<endl;
		
		return;
	}
	void AccountHandler::checkMoneyOfClients() const
	{
		cout<<"[계좌정보 전체 출력]"<<endl; 
		for(int i=0; i<clientIndex; i++)
		{
			clients[i]->showClientInfo();
		}
		cout<<"모든 정보가 출력되었습니다."<<endl;
		
		return; 
	}
	int AccountHandler::searchID(int number) const
	{
		for(int i=0; i<clientIndex; i++)
		{
			if(clients[i]->checkID(number))
			{
				return i;
			}
		}
		
		return -1;
	}
	AccountHandler::~AccountHandler()
	{
		for(int i=0; i<clientIndex; i++)
		{
			delete clients[i];
		}
	}
}
using namespace AccountHandler_h; //#include"AccountHandler.h"




/*Client *clients[100]; 
int clientIndex = 0; */

int main(void)
{
	int choice;
	AccountHandler accountHandler;
	
	while(true)
	{
		choice = accountHandler.menu();
		if(choice == funcNum::OPEN)
		{
			accountHandler.openAccount();
		}
		else if(choice == funcNum::DEPOSIT)
		{
			accountHandler.deposit();
		}
		else if(choice == funcNum::WITHDRAW)
		{
			accountHandler.withdraw();
		}
		else if(choice == funcNum::CHECKMONEY)
		{
			accountHandler.checkMoneyOfClients();
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

/*
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
	clients[index]->setMoney(input);
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
		if(!clients[index]->setMoney(-input))
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
		clients[i]->showClientInfo();
	}
	cout<<"모든 정보가 출력되었습니다."<<endl;
	
	return; 
}

int searchID(int number)
{
	for(int i=0; i<clientIndex; i++)
	{
		if(clients[i]->checkID(number))
		{
			return i;
		}
	}
	
	return -1;
}
*/

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
