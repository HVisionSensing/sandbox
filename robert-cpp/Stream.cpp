/**
 * @file Stream.cpp
 */
#ifndef __STREAM_CPP__
#define __STREAM_CPP__

#include "Stream.h"
#include <iostream>
using namespace std;

Stream::Stream() {
	cout << "Stream:Stream() called" << endl;
	m_number = -1;
}

Stream::Stream(double number) {
	m_number = number;
}

Stream::~Stream() {};

double Stream::Get() const {
	return m_number;
}

bool Stream::Set() {
	SetBase();
	return m_number >= 0;
}

#if 0
void Stream::SetBase() {
	cout << "Stream::SetBase() called"  << endl;
	m_number = -1;
}
#endif

#endif // __STREAM_CPP__
