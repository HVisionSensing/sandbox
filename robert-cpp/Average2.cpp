/**
 * @file Average2.cpp
 */
#include <iostream>
#include "InputStream.h"
using namespace std;

bool Average(InputStream &stream) {
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
	InputStream stream;

	while (true) {
		if (!Average(stream)) {
			break;
		}
	}
	return 0;
}

