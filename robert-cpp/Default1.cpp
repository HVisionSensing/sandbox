/**
 * @file Default1.cpp
 */
#include <iostream>
using namespace std;

void f(int a = 1, int b = 2) {
	cout << "a = " << a << ", b = " << b << endl;
}

int main() {
	f();    // a = 1, b = 2
	f(3);   // a = 3, b = 2
	f(5,6); // a = 5, b = 6
	return 0;
}

