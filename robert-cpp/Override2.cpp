/**
 * @file Override2.cpp
 */
#include "InputStream.h"
#include "ArrayStream.h"
#include <iostream>
using namespace std;

bool Average(Stream& stream) {
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
	InputStream istream;
	Average(istream);

	static const double ARRAY[] = {0.5, 1.5, -1};
	ArrayStream astream(ARRAY);
	Average(astream);

	return 0;
}

