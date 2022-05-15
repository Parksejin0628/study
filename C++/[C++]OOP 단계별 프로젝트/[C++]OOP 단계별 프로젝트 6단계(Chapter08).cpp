/*
[5단계 중점 사안]
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

#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;
const int NAME_LEN = 20;

 
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
		enum creditInfo { CREDIT_A = 7, CREDIT_B = 4, CREDIT_C = 1};
		enum { NORMAL = 1, CREDIT = 2 };
		
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
		int getMoney() const;
		virtual bool setMoney(int money);
		void showClientInfo() const;
		bool checkID(int ID) const;
		~Client();
	};
	
	class NormalAccount : public Client
	{
	private:
		int interestRate;
	public:
		NormalAccount(int iID, char* iName, int iMoney, int iInterestRate);
		virtual bool setMoney(int money);
	};
	
	class HighCreditAccount : public NormalAccount
	{
	private:
		funcNum::creditInfo credit;
	public:
		HighCreditAccount(int ID, char *name, int money, int interestRate, funcNum::creditInfo credit);
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
	int Client::getMoney() const
	{
		return money;
	}
	Client::~Client()
	{
		delete []name;
	}
	//normalAccount
	NormalAccount::NormalAccount(int iID, char* iName, int iMoney, int iInterestRate) : Client(iID, iName, iMoney), interestRate(iInterestRate)
	{
		
	}
	bool NormalAccount::setMoney(int money)
	{
		if(money > 0)
		{
		money += (getMoney() + money) * (interestRate) / 100;
		}
		Client::setMoney(money);
	}
	
	//HighCreditAccount
	HighCreditAccount::HighCreditAccount(int ID, char *name, int money, int interestRate, funcNum::creditInfo credit) : NormalAccount(ID, name, money, interestRate + credit)
	{
		
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
		int interestRate;
		int credit;
		funcNum::creditInfo creditRating;
		int choice = 0; 
		cout<<"[계좌종류 선택]"<<endl; 
		cout<<"1. 보통예금계좌 2. 신용신뢰계좌"<<endl;
		cout<<"선택: ";
		cin>>choice;
			
		cout<<"개설할 계좌 번호 : ";
		cin>>accountID;
		cout<<"고객의 이름 : ";
		cin>>name;
		cout<<"입금할 금액 : ";
		cin>>money;
		cout<<"이자율 : ";
		cin>>interestRate;
		//Normal
		if(choice == funcNum::NORMAL)
		{
			clients[clientIndex] = new NormalAccount(accountID, name, money, interestRate);
			
		}
		else if(choice == funcNum::CREDIT)
		{
			cout<<"신용등급(1toA, 2toB, 3toC): ";
			cin>>credit;
			if(credit == 1)
			{
				creditRating = funcNum::CREDIT_A;
			}
			else if(credit == 2)
			{
				creditRating = funcNum::CREDIT_B;
			}
			else if(credit == 3)
			{
				creditRating = funcNum::CREDIT_C;
			}
			clients[clientIndex] = new HighCreditAccount(accountID, name, money, interestRate, creditRating);
		}
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

