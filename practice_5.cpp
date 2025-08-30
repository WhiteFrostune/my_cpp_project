#include <iostream>
using namespace std;

/*
整型 本质循环，数值超过会倒回去
short        2byte 00        2^16   (-2^15 -> 2^15-1)
int          4byte 0000      2^32   (-2147483648 -> 2147483647)
long         4byte 0000      2^32   (-2^31 -> 2^31-1)    (Windows)  4/8字节（byte）(linux)
long long    8byte 00000000  2^64   (-2^63 -> 2^63-1)
例：short a = 32768 运行输出后为-32768
数值优先选择占用内存少的，即int
*/

int main() {
	short a = 32768;
	int b = 2147483648;
	long c = 1;
	long long d = 1;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	return 0;
}