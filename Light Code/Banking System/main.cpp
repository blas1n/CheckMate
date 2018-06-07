#include "Acc.h"
#include "Bank.h"

int main() {
	AccHandler manager;
	int choice;

	while (true) {
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.makeAcc();
			break;
		case DEPOSIT:

		default:
			cout << "잘못된 입력.." << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}