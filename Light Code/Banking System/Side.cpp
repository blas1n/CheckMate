#ifndef SIDE_H__
#include "Side.h"

Acc* accArr[100];
int accNum;

void Showmenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 출력" << endl;
	cout << "5. 종료" << endl;
}

void MakeAcc()
{
	int id, balance;
	char name[NAME_LEN];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	accArr[accNum++] = new Acc(id, balance, name);
}

void DepositMoney()
{
	int money, id;
	cout << "[입  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl;
}

void WithdrawMoney()
{
	int money, id;
	cout << "[출  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액부족" << endl;
				return;
			}
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl;
}

void ShowAccInfo()
{
	int id;
	cout << "[계좌 정보]" << endl;
	cout << "계좌ID: "; cin >> id;
	for(int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->ShowAcc();
		}
	}
}

void EndAcc()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}
#endif