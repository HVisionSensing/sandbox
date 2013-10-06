/**
 * @file InputStream.cpp
 */
#ifndef __INPUT_STREAM_CPP__
#define __INPUT_STREAM_CPP__

#include <iostream>
#include "InputStream.h"
using namespace std;

InputStream::InputStream() {
	cout << "InputStream::InputStream() called" << endl;
}

InputStream::InputStream(double number) : Stream(number) {
}

#if 0
bool InputStream::Set() {
	cin >> m_number;
	return m_number >= 0;
}
#endif

void InputStream::SetBase() {
	cin >> m_number;
}

#endif //  __INPUT_STREAM_CPP__
