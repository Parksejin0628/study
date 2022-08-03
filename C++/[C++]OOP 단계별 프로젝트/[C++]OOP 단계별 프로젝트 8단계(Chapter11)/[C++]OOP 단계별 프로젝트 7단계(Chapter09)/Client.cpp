#include"BankingCommonDecl.h"
#include"Client.h";

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
	if (this->money + money < 0)
	{
		return false;
	}
	this->money += money;
	return true;
}

void Client::showClientInfo() const
{
	cout << "°èÁÂ¹øÈ£ : " << accountID << endl;
	cout << "ÀÌ¸§ : " << name << endl;
	cout << "ÀÜ¾× : " << money << endl << endl;

	return;
}

bool Client::checkID(int ID) const
{
	if (ID == accountID)
	{
		return true;
	}
	return false;
}

int Client::getMoney() const
{
	return money;
}

Client& Client::operator=(Client& ref)
{
	delete name;
	accountID = ref.accountID;
	money = ref.money;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);

	return *this;
}

Client::~Client()
{
	delete[]name;
}