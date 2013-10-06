/**
 * @file InputStream.h
 */
#ifndef __INPUT_STREAM_H__
#define __INPUT_STREAM_H__

#include "Stream.h"

class InputStream : public Stream {
protected:
	virtual void SetBase();

public:
	InputStream();
	InputStream(double number);
};

#endif // __INPUT_STREAM_H__
