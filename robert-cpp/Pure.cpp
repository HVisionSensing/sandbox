/**
 * @file Pure.cpp
 */
#include <iostream>
using namespace std;

class Bar {
protected:
	int m_number;

public:
	virtual void Set(int number) = 0; // pure virtual function
	int Get() {
		return m_number;
	}
};

class Baz: public Bar {
public:
	void Set(int number) {
		m_number = number;
	};
};

int main() {
	Baz baz;
	baz.Set(1);
	cout << baz.Get() << endl;

	Bar bar;

	return 0;
}
