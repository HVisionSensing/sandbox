/**
 * @file IntArray.cpp
 */
#ifndef __INT_ARRAY_CPP__
#define __INT_ARRAY_CPP__

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "IntArray.h"
using namespace std;

IntArray::IntArray(int size) {
	m_array = new int[size];
	m_size = size;
}

IntArray::IntArray(const IntArray& other)
{
	m_array = new int[other.m_size];
	m_size = other.m_size;
	copy(other.m_array, other.m_array + (m_size *sizeof(*other.m_array)), m_array);
}

IntArray::~IntArray() {
	delete[] m_array;
}

void IntArray::operator=(const IntArray& other) {
	delete[] m_array;
	m_array = new int[other.m_size];
	m_size = other.m_size;
	copy(other.m_array, other.m_array + m_size, m_array);
}

int IntArray::Size() {
	return m_size;
}

void IntArray::Set(int key, int value) {
	CheckKey(key);
	m_array[key] = value;
}

int IntArray::Get(int key) {
	CheckKey(key);
	return m_array[key];
}

void IntArray::CheckKey(int key) {
	if (key < 0 || m_size <= key) {
		cout << "key #" << key << " is invalid" << endl;
		exit(EXIT_FAILURE);
	}
}

#endif // __INT_ARRAY_CPP__
