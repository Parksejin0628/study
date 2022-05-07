/*
[5�ܰ� ���� ���]
1. Banking System�� �ֿ����� ����ϴ� ��Ʈ�� Ŭ������ �����Ѵ�.
2. AccountHandler ��� �Ϲ��� ��Ʈ�� Ŭ������ �����ϰ�, �ռ� ������ �����Լ����� �� Ŭ������ ����Լ��� ���Խ�Ų��.
3. Account ��ü�� ������ ���� ������ �迭�� ������ �� Ŭ������ ����� ���Խ�Ų��.
4. AccountHandler Ŭ���� ������� ���α׷��� ����ǵ��� main �Լ��� �����Ѵ�.

<��Ʈ�� Ŭ����>
1. ��Ʈ�� Ŭ������ Ư¡�� ������ ����.
	- ���α׷� ��ü�� ����� ����Ѵ�. ����, ����� ������ ���� Ŭ�����̴�.
	- ��Ʈ�� Ŭ������ ���� ���α׷��� ��ü ��ɰ� �帧�� �ľ��� �� �ִ�.
2. ��Ʈ�� Ŭ������ ������ ��κ��� Ŭ������ Entity Ŭ������� �Ѵ�.
	- �������� ������ ���ϴ�. ���� ���� �� ������ ���̽��� ����Ǵ� �����͸� �����ϰ� �ִ�.
	- ���α׷��� ����� �ľ��ϴµ� ������ ������ ���Ѵ�.
	- �׷��� ���α׷��󿡼� �����Ǵ� �������� ������ �ľ��ϴ� ���� ������ �ȴ�. 
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
	Ŭ���� �̸� : Client
	Ŭ���� ���� : Emtity Ŭ����
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
	Client::~Client()
	{
		delete []name;
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
		cout<<"[���°���]"<<endl; 
		cout<<"������ ���� ��ȣ : ";
		cin>>accountID;
		cout<<"���� �̸� : ";
		cin>>name;
		cout<<"�Ա��� �ݾ� : ";
		cin>>money;
	
		clients[clientIndex] = new Client(accountID, name, money);
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
			cout<<"�߸��� �����Դϴ�."<<endl; 
		}
	}
	cin>>choice;
	
	return 0;
}

/*
// �޴�â ���� 
int menu()
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

//���� ���� ȭ�� �� ��� 
void openAccount()
{
	int accountID;
	char name[30];
	int money;
	cout<<"[���°���]"<<endl; 
	cout<<"������ ���� ��ȣ : ";
	cin>>accountID;
	cout<<"���� �̸� : ";
	cin>>name;
	cout<<"�Ա��� �ݾ� : ";
	cin>>money;
	
	clients[clientIndex] = new Client(accountID, name, money);
	clientIndex++;
	
	cout<<"���������� �����Ǿ����ϴ�!"<<endl; 
	
	return;
}
 
void deposit()
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

void withdraw()
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
void checkMoneyOfClients()
{
	cout<<"[�������� ��ü ���]"<<endl; 
	for(int i=0; i<clientIndex; i++)
	{
		clients[i]->showClientInfo();
	}
	cout<<"��� ������ ��µǾ����ϴ�."<<endl;
	
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
��� 1. ���°���
 - ������ ���¹�ȣ, �̸�, �Աݾ��� �Է��Ѵ�.
 - �Է��� �������� ���������� ����Ѵ�. 
��� 2. �Ա�
 - �۾��� ���¹�ȣ�� �Է��Ѵ�.
 - �Ա��ϰ��� �ϴ� �ݾ��� �Է��Ѵ�.
 - �Ա��� �ݾ��� ���ؼ� �����͸� �����Ѵ�. 
��� 3. ���
 - �۾��� ���¹�ȣ�� �Է��Ѵ�.
 - ����ϰ��� �ϴ� �ݾ��� �Է��Ѵ�.
 - ��ݱݾ��� ���� �ܾ׺��� ū ��� ���Է��Ѵ�.
 - ��ݱݾ��� ���� �ܾ׺��� ���� ��� ����� �ݾ��� ���� �����͸� �����Ѵ�. 
��� 4. ��ü�� �ܾ���ȸ
 - ��� ���� ������ ����Ѵ�. 

[����]
1. ���¹�ȣ �ߺ� X (�ߺ��˻縦 ���� �ʴ´�.)
2. �Ա�, ����� 0���� ũ��. (�Ա�, ��ݾ� �����˻� X)
3. ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ׸� ���� �� �����Ѵ�.
4. �� �̻��� �� ���� ������ ���� �迭 ����Ѵ�.
5. ���¹�ȣ�� ���������̴�.  

[Client ��ü]
1. ���¸� ������ �� �����ڸ� �̿��Ѵ�.
2. �Ա�, ���, �ܾ� ��ȸ�� ����Լ��� �����Ѵ�. 
*/
