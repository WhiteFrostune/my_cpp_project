#include <iostream>
#include <string>
using namespace std;
int main() {
	int count = 0;
	while (count < 10) {
		cout << "hello world!" << endl;
		count += 1;
	}

	/*
	int count = 0;
	while (1) {     //死循环
		cout << "hello world!" << endl;
		count += 1;
	}
	*/

	/*
	int a, b;
	while (cin >> a >> b) {   // 终止条件
		cout << (a + b) << endl;
	}
	*/
	
	string c;
	while (cin >> c) {
		cout << c + "10086" << endl;
	}

	return 0;
}