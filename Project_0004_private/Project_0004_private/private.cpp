#include <iostream>
#include <string>
using namespace std;

// 接口、方法、函数 是同一个概念
// 1、可以控制读写权限
// 2、可以控制数据的有效性

class Hero {
public:
	void SetName(string name) {
		m_Name = name;
	}

	string GetName() {
		return m_Name;
	}

	int GetSkillCount() {
		return m_SkillCount;
	}

	void SetSpeed(int speed) {
		if (speed > 100 || speed < 500) {
			cout << "速度设置不合法" << endl;
			return;
		}
		m_Speed = speed;
	}

private:
	string  m_Name;            // 可读，可写
	int     m_SkillCount = 4;  // 只读
	int     m_Speed;           // 只写

};

int main() {
	Hero h;
	/*
	h.m_Name = 1234
	h.m_SkillCount = 123
	h.m_Speed = 345
	*/
	h.SetName("剑圣");
	cout << "英雄的名字是：" << h.GetName() << endl;
	cout << "英雄的技能数是：" << h.GetSkillCount() << endl;
	h.SetSpeed(666);
	return 0;

}