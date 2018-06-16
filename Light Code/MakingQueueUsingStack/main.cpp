#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

//Implement this class
//Please use stack only
class Queue {
private:
	stack<int> inputSt;
	stack<int> outputSt;
private:
	void OutputReady() {
		stack<int> buffer;

		while (!(inputSt.empty())) {
			outputSt.push(inputSt.top());
			buffer.push(inputSt.top());
			inputSt.pop();
		}
		
		buffer.pop();
		while (!(buffer.empty())) {
			inputSt.push(buffer.top());
			buffer.pop();
		}
	}
public:
	/*
	* Description:
	* Time complexity:
	* Space complexity:
	*/
	void enqueue(int v) {
		inputSt.push(v);
	}

	/*
	* Description:
	* Time complexity:
	* Space complexity:
	*/
	int dequeue() {
		int val;

		OutputReady();
		val = outputSt.top();
		
		while (!(outputSt.empty()))
			outputSt.pop();

		return val;
	}
};

int main(int argc, const char *argv[]) {
	Queue queue;
	string line;
	getline(cin, line);
	int count = stoi(line);
	for (int i = 0; i < count; ++i) {
		getline(cin, line);
		stringstream ss(line);
		string token;
		getline(ss, token, ' ');
		if (token == "ENQUEUE") {
			getline(ss, token, ' ');
			queue.enqueue(stoi(token));
		}
		else if (token == "DEQUEUE") {
			cout << queue.dequeue() << endl;
		}
	}

	system("pause");
	return 0;
}