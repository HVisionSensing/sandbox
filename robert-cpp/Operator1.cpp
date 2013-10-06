/**
 * @file Operator1.cpp
 */
#include <iostream>
#include "IntArray.h"
using namespace std;

int main() {
	IntArray a(5);

	for (int key = 0; key < a.Size(); key++) {
		int value;
		cin >> value;
		a.Set(key, value);
	}

#if 1
	//	IntArray b(5);
	//	b = a;
	IntArray b(a);
	for (int key = 0; key < b.Size(); key++) {
		b.Set(key, 2 * b.Get(key));
	}

	for (int key = 0; key < a.Size(); key++) {
		cout << a.Get(key) << " -> " << b.Get(key) << endl;
	}
#endif
	return 0;
}
