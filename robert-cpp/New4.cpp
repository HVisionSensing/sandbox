/**
 * @file New4.cpp
 */
#include "InputStream.h"
#include "ArrayStream.h"
#include <iostream>
using namespace std;

Stream* CreateStream() {
	char ch;

	while (true) {
		cout << "i: InputStream, a: ArrayStream > " << flush;
		cin >> ch;

		switch (ch) {
		case 'i':
			return new InputStream();
		case 'a':
			const double ARRAY[] = {1, 2, 3, -1};
			const int SIZE = sizeof(ARRAY) / sizeof(*ARRAY);
			return new ArrayStream(ARRAY, SIZE);
		}
	}
	return NULL;
}

double Sum(Stream& stream) {
	double sum = 0;
	while (stream.Set()) {
		sum += stream.Get();
	}
	return sum;
}

int main() {
	for (int i = 0; i < 3; i++) {
		Stream *stream = CreateStream();
		double sum = Sum(*stream);
		cout << "total -> " << sum << endl;
		delete stream;
	}
	return 0;
}
