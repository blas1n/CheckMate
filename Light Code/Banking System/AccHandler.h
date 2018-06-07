#ifndef __ACCHANDLER_H__
#define __ACCHANDLER_H__

#include "Acc.h"
#include "AccArray.h"

class AccHandler
{
private:
	BoundCheckAccPtrArr accArr;
	int accNum;
public:
	AccHandler();
	void ShowMenu() const;
	void MakeAcc();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
protected:
	void MakeNormalAcc();
	void MakeCreditAcc();
};

#endif
