/*
[5�ܰ� ���� ���]
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

#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;
const int NAME_LEN = 20;

 
/*
	Ŭ���� �̸� : Client
	Ŭ���� ���� : Emtity Ŭ����
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
		cout<<"���¹�ȣ : "<<accountID<<endl;
		cout<<"�̸� : "<<name<<endl;
		cout<<"�ܾ� : "<<money<<endl<<endl;
		
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
	Ŭ���� �̸� : AccountHandler
	Ŭ���� ���� : ��Ʈ��(Constrol) Ŭ����
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
		cout<<"1. ���°���"<<endl;
		cout<<"2. �� ��"<<endl;
		cout<<"3. �� ��"<<endl;
		cout<<"4. �������� ��ü ���"<<endl;
		cout<<"5. ���α׷� ����"<<endl;
		cout<<"����: ";
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
		cout<<"[�������� ����]"<<endl; 
		cout<<"1. ���뿹�ݰ��� 2. �ſ�ŷڰ���"<<endl;
		cout<<"����: ";
		cin>>choice;
			
		cout<<"������ ���� ��ȣ : ";
		cin>>accountID;
		cout<<"���� �̸� : ";
		cin>>name;
		cout<<"�Ա��� �ݾ� : ";
		cin>>money;
		cout<<"������ : ";
		cin>>interestRate;
		//Normal
		if(choice == funcNum::NORMAL)
		{
			clients[clientIndex] = new NormalAccount(accountID, name, money, interestRate);
			
		}
		else if(choice == funcNum::CREDIT)
		{
			cout<<"�ſ���(1toA, 2toB, 3toC): ";
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
	
		cout<<"���������� �����Ǿ����ϴ�!"<<endl; 
		
		return;
	}
	void AccountHandler::deposit()
	{
		int input = 0;
		int index = 0;
	
		cout<<"[�� ��]"<<endl;
		while(true)
		{
			cout<<"�Ա��� ���� ��ȣ : ";
			cin>>input;
			index = searchID(input);
			if(index == -1)
			{
				cout<<"���� ���� ��ȣ�Դϴ�. �ٽ� �Է��� �ֽʽÿ�."<<endl;
				continue;
			}
			break;
		}
		cout<<"�Ա��� �ݾ� : ";
		cin>>input;
		clients[index]->setMoney(input);
		cout<<"���������� ó���Ǿ����ϴ�."<<endl;
	
		return;
	}
	void AccountHandler::withdraw()
	{
		int input = 0;
		int index = 0;
	
		cout<<"[�� ��]"<<endl;
		while(true)
		{
			cout<<"����� ���� ��ȣ : ";
			cin>>input;
			index = searchID(input);
			if(index == -1)
			{
				cout<<"���� ���� ��ȣ�Դϴ�. �ٽ� �Է��� �ֽʽÿ�."<<endl;
				continue;
			}
			break;
		}
		while(true)
		{
			cout<<"�Ա��� �ݾ� : ";
			cin>>input;
			if(!clients[index]->setMoney(-input))
			{
				cout<<"�ܾ׺��� ū �ݾ��Դϴ�. �ٽ� �Է��� �ֽʽÿ�."<<endl;
				continue;
			}
			break;
		} 
		cout<<"���������� ó���Ǿ����ϴ�."<<endl;
		
		return;
	}
	void AccountHandler::checkMoneyOfClients() const
	{
		cout<<"[�������� ��ü ���]"<<endl; 
		for(int i=0; i<clientIndex; i++)
		{
			clients[i]->showClientInfo();
		}
		cout<<"��� ������ ��µǾ����ϴ�."<<endl;
		
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
			cout<<"�߸��� �����Դϴ�."<<endl; 
		}
	}
	cin>>choice;
	
	return 0;
}

