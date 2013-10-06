/**
 * @file CopyConstructor.cpp
 */
#include <iostream>
#include <cstring>
using namespace std;

#define IMPL_COPY_CONSTRUCTOR

class Foo {
private:
	int* m_number;
public:
	Foo(); // constructor
	~Foo(); // destructor
#ifdef IMPL_COPY_CONSTRUCTOR
	Foo(const Foo& other); // copy constructor
#endif
	void Set(int number);
	int Get();
};

Foo::Foo() {
	m_number = new int;
	*m_number = -1;
}

Foo::~Foo() {
	delete m_number;
}

#ifdef IMPL_COPY_CONSTRUCTOR
Foo::Foo(const Foo& other) {
	m_number = new int;
	memcpy(m_number, other.m_number, sizeof(int));
}
#endif

void Foo::Set(int number) {
	*m_number = number;
}

int Foo::Get() {
	return *m_number;
}

int Trace(int number) {
	cout << "[Trace] #" << number << endl;
}

int ShowFoo(Foo foo) {
	Trace(2);
	cout << foo.Get() << endl;
	Trace(3);
}

int main() {
	Foo foo;
	foo.Set(10);

	Trace(1);
	ShowFoo(foo);
	Trace(4);

	return 0;
}
