/**
 * @file Temporary2.cpp
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
	void Set(int n) {
		m_n = n;
	}
	int Get() const {
		return m_n;
	}

private:
	int m_n;
};

void Trace(int n) {
	cout << "[Trace] #" << n << endl;
}

Hoge& One(Hoge& h) {
	h.Set(1); // 単なる参照への代入
	return h;
}

Hoge Two() {
	Hoge h(2); // temporary objectが生成される
	return h;
}

int main() {
	Trace(0);
	Hoge one(-1);
	Hoge two(-2);

	Trace(1);
	one = One(one);
	cout << one.Get() << endl;

	Trace(2);
	two = Two();
	cout << two.Get() << endl;

	Trace(3);
	return 0;
}
		
