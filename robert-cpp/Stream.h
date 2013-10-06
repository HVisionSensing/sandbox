/**
 * @file Stream.h
 */
#ifndef __STREAM_H__
#define __STREAM_H__

class Stream {
public:
	Stream(); // constructor
	Stream(double number);
	virtual ~Stream();
	double Get() const; // getter
	bool Set(); // setter

protected:
	double m_number;
	virtual void SetBase() = 0;
};

#endif __STREAM_H__
