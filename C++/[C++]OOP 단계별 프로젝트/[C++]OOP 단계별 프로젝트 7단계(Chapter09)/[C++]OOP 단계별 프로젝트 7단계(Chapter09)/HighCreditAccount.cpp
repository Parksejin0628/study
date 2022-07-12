#include"HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int ID, char *name, int money, int interestRate, funcNum::creditInfo credit) : NormalAccount(ID, name, money, interestRate + credit)
{

}