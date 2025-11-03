#include <iostream>
using namespace std;
int main() {
	/*
	int a = 0;
	do {
		cout << a << endl;
		a += 1;
	} while (a < 3);
	
	cout << "----" << endl;

	a = 0;
	while (a < 3) {
		cout << a << endl;
		a += 1;
	}
	
	do 先执行，再循环
	while 直接执行
	*/

	int a = 3;
	do {
		cout << a << endl;
		a += 1;
	} while (a < 3);

	cout << "----" << endl;

	a = 3;
	while (a < 3) {
		cout << a << endl;
		a += 1;
	}

	return 0;
}