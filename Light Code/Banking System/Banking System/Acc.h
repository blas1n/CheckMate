#ifndef __ACC_H__
#define __ACC_H__

class Acc
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Acc(int ID, int money, char* name);
	Acc(const Acc& ref);
	Acc& operator= (const Acc& ref);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Acc();
};

#endif