/**
 * @file ArrayStream.cpp
 */
#ifndef __ARRAY_STREAM_CPP__
#define __ARRAY_STREAM_CPP__

#include <iostream>
#include <algorithm>
#include "ArrayStream.h"
using namespace std;

ArrayStream::ArrayStream(const double *array, int size) {
	m_array = new double[size];
	copy(array, array + size, m_array);
//	memcpy(m_array, (void *)array, size * sizeof(double));
	m_index = 0;
}

ArrayStream::~ArrayStream() {
	cout << "ArrayStream::~ArrayStream() called" << endl;
	delete[] m_array;
}

void ArrayStream::SetBase() {
	m_number = m_array[m_index];
	if (m_number >= 0) m_index++;
}

#if 0
bool ArrayStream::Set() {
	m_number = m_array[m_index];
	if (m_number >= 0) {
		m_index++;
		return true;
	} else {
		return false;
	}
}
#endif

#endif __ARRAY_STREAM_CPP__
