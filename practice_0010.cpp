#include <iostream>
using namespace std;

int main() {
	
	int i = 8;
	int j = 8;
	
	int x = i++;  // 先把 8 赋值给 x，然后再递增为 9
	int y = ++j;  // 先递增为 9，再把 9 赋值给 y
	
	cout << x << endl;   // 8
	cout << y << endl;   // 9
	
	cout << i++ << endl; // 9 先输出，再递增
	cout << i << endl;   // 10


	x = 6;
	y = 9;
	
	x = y; // 将 y 的值赋给 x
	cout << x << endl; // 9

	x += y; // x = x + y
	cout << x << endl; // 18

	x -= y; // x = x - y
	cout << x << endl; // 9

	x *= y; // x = x * y
	cout << x << endl; // 81

	x /= y; // x = x / y
	cout << x << endl; // 9

	x %= y; // x = x % y
	cout << x << endl; // 0

	/*
	== 等于
	!= 不等于
	>  大于
	<  小于
	>= 大于等于
	<= 小于等于
	*/

	int a = 6;
	int b = 9;
	// 以下均为逻辑计算结果，所以都是布尔数
	cout << (a == b) << endl; // 0
	cout << (a != b) << endl; // 1
	cout << (a > b) << endl;  // 0
	cout << (a < b) << endl;  // 1
	cout << (a >= b) << endl; // 0
	cout << (a <= b) << endl; // 1

	return 0;
}
