/**
 * @file Temporary1.cpp
 */
#include <iostream>
using namespace std;

class Hoge {
public:
	Hoge(int n) : m_n(n) {
		cout << "Hoge()    : " << m_n << endl;
	}
	Hoge(const Hoge& h) {
		m_n = h.m_n;
		cout << "Hoge(&h)  : " << m_n << endl;
	}
	virtual ~Hoge() {
		cout << "~Hoge()   : " << m_n << endl;
	}
	void operator=(const Hoge& h) {
		cout << "operator= : " << m_n << endl;
		m_n = h.m_n;
	}
	int Get() {
		return m_n;
	}

private:
	int m_n;
};

void Trace(int n) {
	cout << "[Trace] #" << n << endl;
}

int main() {
	Trace(0);
	Hoge hoge(1);
	Trace(1);
	hoge = Hoge(2); // Hoge(2)よりtemporary objectが作られる
	cout << hoge.Get() << endl;
	Trace(2);
	return 0;
}
		
