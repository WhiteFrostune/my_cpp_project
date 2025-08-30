#include <iostream>
#include <iomanip>  // 用于控制输出格式
#include <cmath>    // 提供数学函数

/*
float  4字节
double 8字节
*/

#define eps 1e-7 // 定义一个很小的常数，用于浮点数比较

using namespace std;
int main() {
	float a = 3.1415926f;                   // 单精度浮点数，末尾的 'f' 表示这是 float 类型
	double b = 3.14159261111111111111111;   // 双精度浮点数，精度更高
	double c = 1.5e5;   //1.5*100000
	double d = 1.5e-5;  //1.5*0.00001
	cout << setprecision(10) << a << endl;  // 以10位精度输出a
	cout << setprecision(26) << b << endl;  // 以26位精度输出b
	cout << c << endl;
	cout << d << endl;
	// 这里是关键部分: 浮点数的精度问题
	double x = 1.0 / 7435127347 * 7435127347;
	/* 
	理论上应该是(1.0 / A)* A = 1.0
	但由于浮点数的精度限制，结果可能不是精确的1.0
	使用近似比较而不是直接比较 x == 1
	*/
	if (fabs(x - 1) < eps) {    // fabs()是求绝对值的函数
		cout << "hhh" << endl;  // 如果x与1的差值很小，就输出"hhh"
	}
	cout << x << endl;
	cin.get();
	return 0;
}