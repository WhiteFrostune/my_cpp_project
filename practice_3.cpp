#include <iostream>
using namespace std;
#define X 1+2 //宏定义 常量
int x = 7; //变量
const int y = 1; //常量
int main() {
	cout <<  X * X  << endl;
	x = (x + 1);
	cout << x + y << endl;
	cin.get();
	return 0;
}