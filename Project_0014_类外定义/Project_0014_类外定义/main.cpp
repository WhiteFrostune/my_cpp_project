#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
	T* elements;
	int size;
public:
	DynamicArray(int n); 
	~DynamicArray();
	T& operator[](int index); 
	void update(int index, T value); // 更新第 index 个索引的元素，把它的值改为 value
};

template<typename T>
DynamicArray<T>::DynamicArray(int n) : size(n) {
	elements = new T[n];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] elements;
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
	return elements[index];
}

template<typename T>
void DynamicArray<T>::update(int index, T value) {
	elements[index] = value;
}

int main() {
	DynamicArray<char> dac(10);
	dac[5] = 'h';
	dac.update(5, 'u');
	cout << dac[5] << endl;
	return 0;
}