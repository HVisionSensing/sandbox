/**
 * @file New1.cpp
 */
#include <iostream>
using namespace std;

int main() {
	int *p;

	p = new int;
	*p = 1;
	cout << *p << endl; // 1と表示
	delete p;

	return 0;
}
