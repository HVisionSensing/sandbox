/**
 * @file Thread.cpp
 */
#include <iostream>
#include <pthread.h>
using namespace std;

/**
 * @brief スレッドクラス
 */
class Thread {
public:
	Thread();
	virtual ~Thread();
	virtual int start();
	virtual int join();
	virtual void run();

protected:
	pthread_t thread_id;

private:
	static void* start_routine(void* arg);
};

Thread::Thread()
	: thread_id(0) {
}

Thread::~Thread() {
}

int Thread::start() {
	int ret = pthread_create(&(this->thread_id),
							 NULL,
							 Thread::start_routine,
							 this);
	return ret;
}

int Thread::join() {
	int ret = pthread_join(this->thread_id, NULL);
	return ret;
}

void Thread::run() {
}

void* Thread::start_routine(void* arg) {
	if (arg != NULL) {
		Thread* this_ = reinterpret_cast<Thread*>(arg);
		this_->run();
	}
	return NULL;
}


/**
 * @brief スレッドクラス
 */
class SayThread : public Thread {
public:
	void run();

public:
	string word;
};

void SayThread::run() {
	sleep(2);
	cout << "Hello, " << this->word << endl;
}

int main() {
	SayThread th;
	th.word = "Foo";
	th.start();
	th.join();
	return 0;
}
