#ifndef  __BANK_H__
#define __BANK_H__

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

namespace ComBank {
	enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
	enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
	enum { NORMAL = 1, CREDIT };
}

#endif
