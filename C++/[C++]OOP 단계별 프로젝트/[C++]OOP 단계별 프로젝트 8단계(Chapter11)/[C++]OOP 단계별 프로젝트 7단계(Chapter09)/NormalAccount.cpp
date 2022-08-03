#include"NormalAccount.h"

NormalAccount::NormalAccount(int iID, char* iName, int iMoney, int iInterestRate) : Client(iID, iName, iMoney), interestRate(iInterestRate)
{

}
bool NormalAccount::setMoney(int money)
{
	if (money > 0)
	{
		money += (getMoney() + money) * (interestRate) / 100;
	}
	Client::setMoney(money);

	return true;
}