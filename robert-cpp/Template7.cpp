/**
 * @file Template7.cpp
 */
#include <iostream>
using namespace std;

template <int N> class SBit {
public:
	static const int VALUE = 1 << N;
};

int main() {
	cout << SBit<0>::VALUE << ' '
		 << SBit<1>::VALUE << ' '
		 << SBit<2>::VALUE << ' ' << endl;
	return 0;
}

