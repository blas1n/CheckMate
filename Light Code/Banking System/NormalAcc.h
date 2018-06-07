#ifndef __NORMALACC_H__
#define __NORMALACC_H__

#include "Acc.h"

class NormalAcc : public Acc
{
private:
	int interRate;
public:
	NormalAcc(int ID, int money, char* name, int rate)
		: Acc(ID, money, name), interRate(rate)
	{}

	virtual void Deposit(int money)
	{
		Acc::Deposit(money);
		Acc::Deposit(money * (interRate / 100.0));
	}
};


#endif