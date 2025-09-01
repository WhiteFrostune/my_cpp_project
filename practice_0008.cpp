#include <iostream>
#include <string>

/*
i=input
o=output
*/

using namespace std;

int main() {
	cout << "请开始您的输入：\n";
	// 1.整型的输入
	int a;
	cin >> a;
	cout << "a的值为：" << a << endl;
	// 2.浮点型的输入
	double b;
	cin >> b;
	cout << "b的值为：" << b << endl;
	// 3.字符型的输入
	char c;
	cin >> c;
	cout << "c的值为：" << c << endl;
	// 4.字符串型的输入
	string d;
	cin >> d;
	cout << "d的值为：" << d << endl;
	// 5.布尔类型的输入
	bool e = false;
	e = !e; // 取反，即为true
	cin >> e;
	cout << "e的值为：" << e << endl;
	return 0;
}
