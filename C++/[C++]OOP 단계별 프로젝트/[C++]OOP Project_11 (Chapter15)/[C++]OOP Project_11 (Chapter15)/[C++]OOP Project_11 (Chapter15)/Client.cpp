#include"BankingCommonDecl.h"
#include"Client.h"

Client::Client(int accountID, String name, int money) : accountID(accountID), money(money), name(name)
{

}

Client::Client(const Client &copy) : accountID(copy.accountID), money(copy.money), name(copy.name)
{
	
}

bool Client::setMoney(int money)
{
	if (this->money + money < 0)
	{
		cout << "check / Client_setMoney / false" << endl;
		return false;
	}
	cout << "check / Client_setMoney / true" << endl;
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
	accountID = ref.accountID;
	money = ref.money;
	name = ref.name;

	return *this;
}

Client::~Client()
{
	
}