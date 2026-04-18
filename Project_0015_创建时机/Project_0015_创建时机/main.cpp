#include <iostream>
using namespace std;

class Player {
public:
	void run() {
		cout << "跑步" << endl;
	}
};

class Ball {
public:
	void drop() {
		cout << "下落" << endl;
	}
};

template<class T>
class Test {
	T obj;
public:
	void move1() {
		obj.run();
	}
	void move2() {
		obj.drop();
	}
};


int main() {
	Test<Player> test1;
	test1.move1();
	// test1.move2();

	Test<Ball> test2;
	// test2.move1();
	test2.move2();
	return 0;
}