#include "Bank.h"
#include "AccArray.h"

BoundCheckAccPtrArr::BoundCheckAccPtrArr(int len = 100) : arrlen(len)
{
	arr = new Acc_Ptr[len];
}

Acc_Ptr& BoundCheckAccPtrArr::operator[] (int idx)
{
	if (idx < 0 || idx > arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

Acc_Ptr BoundCheckAccPtrArr::operator[] (int idx) const
{
	if (idx < 0 || idx > arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

int BoundCheckAccPtrArr::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccPtrArr::~BoundCheckAccPtrArr()
{
	delete[] arr;
}