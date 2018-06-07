#ifndef __ACCARRAY_H__
#define __ACCARRAY_H__

#include "Acc.h"
typedef Acc* Acc_Ptr;

class BoundCheckAccPtrArr
{
private:
	Acc_Ptr * arr;
	int arrlen;
	BoundCheckAccPtrArr(const BoundCheckAccPtrArr& arr) {}
	BoundCheckAccPtrArr& operator=(const BoundCheckAccPtrArr& arr) {}
public:
	BoundCheckAccPtrArr(int len = 100);
	Acc_Ptr& operator[] (int idx);
	Acc_Ptr operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckAccPtrArr();
};

#endif