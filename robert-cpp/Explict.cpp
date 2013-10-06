/**
 * @file Explicit.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;

#define USE_EXPLICIT

class Foo {
public:
#ifdef USE_EXPLICIT
	explicit Foo(int size)
#else
	Foo(int size)
#endif
	{
		cout << "Foo() called" << endl;
		m_size = size;
		m_array = new int(size);
	}
	virtual ~Foo() {
		cout << "~Foo() called" << endl;
		delete[] m_array;
	}
	int Size() const {
		return m_size;
	}

private:
	int m_size;
	int* m_array;
};

void ShowSize(const Foo& f) {
	cout << f.Size() << endl;
}

int main() {

	ShowSize(4);

	return 0;
}

