#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
	T* elements;
	int size;
public:
	DynamicArray(int n) : size(n) {
		elements = new T[n];
	}
	~DynamicArray() {
		delete[] elements;
	}
	T& operator[](int index) {
		return elements[index];
	}
};

int main() {
	DynamicArray<double> da(100);
	da[1] = 1.5;
	da[9] = 3.2;
	cout << da[0] << ' ' << da[1] << endl;

	DynamicArray<char> dac(10);
	dac[0] = 'A';
	dac[1] = 'C';
	dac[9] = 'M';
	cout << dac[0] << dac[1] << dac[9] << endl;
	return 0;
}