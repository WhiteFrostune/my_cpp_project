#include <iostream>
using namespace std;

// 常函数
class Hero {
public:
	Hero() : m_Hp(0) {}

	int getHp() const {
		// m_Hp = m_Hp + 1;
		return m_Hp;
	}

	int setHp(int hp) {
		m_Hp = hp;
	}

private:
	int m_Hp;
};

int main() {
	const Hero h;
	// h.setHp(100);
	h.getHp();
	return 0;
}