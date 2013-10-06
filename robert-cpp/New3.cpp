/**
 * @file New3.cpp
 */
#include "ArrayStream.h"
#include <iostream>
using namespace std;

int main() {
	const double ARRAY[] = {1, 2, 3, -1};
	const int SIZE = sizeof(ARRAY) / sizeof(*ARRAY);

	ArrayStream stream(ARRAY, SIZE);
	while(stream.Set()) {
		cout << stream.Get() << ' ' << flush;
	}
	cout << endl;
}
