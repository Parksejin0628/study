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
			cout<<"�߸��� �����Դϴ�."<<endl; 
		}
	}
	cin>>choice;
	
	return 0;
}

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

void openAccount()
{
	cout<<"[���°���]"<<endl; 
	cout<<"������ ���� ��ȣ : ";
	cin>>clients[clientIndex].accountNumber;
	cout<<"���� �̸� : ";
	cin>>clients[clientIndex].name;
	cout<<"�Ա��� �ݾ� : ";
	cin>>clients[clientIndex].money;
	cout<<"���������� �����Ǿ����ϴ�!"<<endl; 
	clientIndex++;
	
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
	clients[index].money += input;
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
		if(input > clients[index].money)
		{
			cout<<"�ܾ׺��� ū �ݾ��Դϴ�. �ٽ� �Է��� �ֽʽÿ�."<<endl;
			continue;
		}
		break;
	} 
	
	clients[index].money -= input;
	cout<<"���������� ó���Ǿ����ϴ�."<<endl;
	
	return;
}
void checkMoneyOfClients()
{
	cout<<"[�������� ��ü ���]"<<endl; 
	for(int i=0; i<clientIndex; i++)
	{
		cout<<"���¹�ȣ : "<<clients[i].accountNumber<<endl;
		cout<<"�̸� : "<<clients[i].name<<endl;
		cout<<"�ܾ� : "<<clients[i].money<<endl<<endl;
	}
	cout<<"��� ������ ��µǾ����ϴ�."<<endl;
	
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
*/
