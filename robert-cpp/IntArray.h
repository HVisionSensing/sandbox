/**
 * @file IntArray.h
 */
#ifndef __INT_ARRAY_H__
#define __INT_ARRAY_H__

class IntArray {
private:
	int* m_array;
	int m_size;
	void CheckKey(int key);

public:
	IntArray(int size);
	IntArray(const IntArray& other);
	~IntArray();
	void operator=(const IntArray &other);
	int Size();
	void Set(int key, int value);
	int Get(int key);
};

#endif // __INT_ARRAY_H__
