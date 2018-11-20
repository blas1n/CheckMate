#include "AVLTree.h"
#include <iostream>

using namespace std;

bool Choice(int& choice);
void Input(string* key, string* value);

int main() {
	AVLTree* avl = new AVLTree();
	AVLNode* root = nullptr;
	AVLNode* result = nullptr;

	string inputKey, inputValue;
	int choice;

	while (Choice(choice)) {
		switch (choice) {
		case 1:
			Input(&inputKey, nullptr);
			result = avl->Search(root, inputKey);
			cout << result << endl;
			break;

		case 2:
			Input(&inputKey, &inputValue);
			root = avl->Insert(root, inputKey, inputValue);
			break;
		}

		cout << endl << endl;
	}

	delete avl;
	avl = nullptr;

	return 0;
}

bool Choice(int& choice) {
	cout << "1. 단어 검색\n";
	cout << "2. 단어 추가\n";
	cout << "0. 종료\n" << endl;

	cout << "선택. ";
	cin >> choice;
	cout << endl;

	return choice != 0;
}

void Input(string* key, string* value) {
	if (key) {
		cout << "단어를 입력하세요. ";
		cin >> (*key);
	}

	if (value) {
		cout << "뜻을 입력하세요. ";
		cin >> (*value);
	}
}