/**
 * @file Average3.cpp
 */
#include <iostream>
#include "ArrayStream.h"
using namespace std;

bool Average(ArrayStream &stream) {
	int count;
	double average = 0;

	for (count = 0; stream.Set(); count++) {
		average += stream.Get();
	}
	if (count == 0) {
		return false;
	}

	average /= count;
	cout << "average = " << average << endl;
	return true;
}

int main() {
	const double ARRAY1[] = {1, 2, 3, -1};
	const double ARRAY2[] = {0.5, 1.5, -1};
	const double ARRAY3[] = {-1};
	const double* ARRAY_LIST[] = {ARRAY1, ARRAY2, ARRAY3};
	const int size = sizeof(ARRAY_LIST) / sizeof(*ARRAY_LIST);

	for (int count = 0; count < size; count++) {
		ArrayStream stream(ARRAY_LIST[count]);
		if (!Average(stream)) {
			break;
		}
	}
	return 0;
}

	
