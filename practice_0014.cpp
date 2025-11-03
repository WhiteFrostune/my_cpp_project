#include <iostream>
using namespace std;
int main() {

	/*
	int sum = 0;
	for (int i = 1; i <= 5; ++i) {  // (初始化；条件；循环执行)
			sum += i;
		}
	cout << sum << endl;
	*/

	/*1.写法1
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += i;
		}
		cout << sum << endl;
	}
	*/
	
	/*2.写法2
	int n;
	while (cin >> n) {
		int sum = 0;
		int i =1;
		for (; i <= n; ++i) {
			sum += i;
		}
		cout << sum << endl;
	}
	*/

	/*3.写法3
	int n;
	while (cin >> n) {
		int sum;
		int i;
		for (sum = 0, i = 1; i <= n; ++i) {
			sum += i;
		}
		
		cout << sum << endl;
		cout << "----" << endl;
	}
	*/
	
	/*4.写法4：死循环
	int n;
	while (cin >> n) {
		int sum;
		int i;
		for (sum = 0, i = 1; ; ++i) {
			sum += i;
		}

		cout << sum << endl;
		cout << "----" << endl;
	}
	*/

	int n;
	while (cin >> n) {
		int sum;
		int i;
		for (sum = 0, i = 1; i <= n; ) {
			sum += i;
			++i;
		}

		cout << sum << endl;
		cout << "----" << endl;
	}
	return 0;
}