/**
 * @file Specialization2.cpp
 */
#include <iostream>
#include <utility>
using namespace std;

template <typename TYPE>
class Value
{
public:
	Value(const TYPE& value) : m_value(value) {};
	void Show() const { cout << m_value << endl; };

private:
	TYPE m_value;
};

template <typename FIRST, typename SECOND>
class Value< pair<FIRST, SECOND> >
{
public:
	Value(const FIRST& first, const SECOND& second) :
		m_value(first, second) {}
	void Show() {
		cout << "1st : " << m_value.first << endl
			 << "2nd : " << m_value.second << endl;
	}

private:
	pair<FIRST, SECOND> m_value;
};

int main() {
	Value<int> n(42);
	n.Show();

	Value< pair<int, const char*> > p(1,"hoge");
	p.Show();

	return 0;
}


