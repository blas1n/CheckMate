#include "Acc.h"
#include "Bank.h"

Acc::Acc(int ID, int money, char* name)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Acc::Acc(const Acc& ref)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Acc& Acc::operator= (const Acc& ref)
{
	accID = ref.accID;
	balance = ref.balance;

	delete[] cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);

	return *this;
}

int Acc::GetAccID() const
{
	return accID;
}

void Acc::Deposit(int money)
{
	balance += money;
}

int Acc::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Acc::ShowAccInfo() const
{
	cout << "°èÁÂ ID: " << accID << endl;
	cout << "ÀÌ   ¸§: " << cusName << endl;
	cout << "ÀÜ   ¾×: " << balance << endl;
}

Acc::~Acc()
{
	delete[] cusName
}