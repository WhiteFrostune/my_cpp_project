#include <iostream>
using namespace std;
int main() {
	char a = 'y';    // 声明字符变量a
	char b = 'z';

	cout << a << endl;           
	cout << int(a) << endl;      // 将a转换为整数输出（ASCII码）
	cout << b - a << endl;       // 计算b和a的ASCII码差值

	b = 120;                    // 将整数120赋值给字符b
	cout << b << endl;          
	cin.get();
	return 0;
}
