/**
 * @file ArrayStream.h
 */
#ifndef __ARRAY_STREAM_H__
#define __ARAAY_STREAM_H__

#include "Stream.h"

class ArrayStream : public Stream {
public:
	ArrayStream(const double* array, int size);
	virtual ~ArrayStream();
//	bool Set();

protected:
	virtual void SetBase();

private:
	double* m_array;
	int m_index;
};

#endif __ARRAY_STREAM_H__
