#include <iostream>
using namespace std;

class Animal {
public:
	virtual void eat() = 0;
};

class Cat {
public:
	virtual void eat() {
		cout << "猫在吃东西" << endl;
	}
};
int main() {
	Cat c;
	c.eat();

	return 0;
}