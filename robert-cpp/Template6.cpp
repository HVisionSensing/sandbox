/**
 * @file Template6.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

template <template<typename, typename> class TMPL> class Foo {
public:
	void CheckTypeID() const {
		cout << ((typeid(m_v) == typeid(vector<int>)) ? "true" : "false") << endl;
	}

private:
	TMPL< int, allocator<int> > m_v;
};

int main() {
	Foo<vector> foo; // この場合、m_vはvector<int>となる

	foo.CheckTypeID();

	return 0;
}

