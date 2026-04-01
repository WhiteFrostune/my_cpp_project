#include <iostream>
using namespace std;

class Animal {
public:
	virtual void eat() {
		cout << "动物在吃东西" << endl;
	}
};

class Cat : public Animal {
public:
	void eat() {
		cout << "猫在吃东西" << endl;
	}
};

class Pig : public Animal {
public:
	void eat() {
		cout << "猪在吃东西" << endl;
	}
};

void eat(Animal& a) {
	a.eat();
}

void test() {
	Cat c;
	Pig p;
	eat(c);
	eat(p);
}

int main() {
	test();
	return 0;
}