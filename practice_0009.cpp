#include <iostream>
using namespace std;

int main() {
	int a = 6;
	int b = 9;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;       // 整除，直接截断而非四舍五入取整
	cout << a * 1.0 / b << endl; //转化为浮点数运算

	a = 10000000;
	b = 100000;
	cout << a * b << endl;               // 直接输出，数据溢出，数据损坏
	cout << (long long)a * b << endl; // 强制转化为long long类型，防止数据损坏

	a = -1;
	b = 2;
	cout << a / b << endl; // 不是取整而是向零截断

	a = +6;
	b = -a;
	int c = -(-a);
	cout << a << " " << b << " " << c << endl;

	char A = 'A';  // char类型是字符，只能用单引号，不能用双引号，双引号是字符串
	A = A + 1;     // ASCII码相加减，运算结果为字符
	cout << A << endl;

	return 0;
}
