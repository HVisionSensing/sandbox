/**
 * @file Template5.cpp
 */
#include <iostream>
using namespace std;

template <typename TYPE = char> // デフォルトタイプはchar
class FortyTwo {
public:
	TYPE Get() const {
		return 65; // ASCIIコードで'A'
	};
};

int main() {
	FortyTwo<> ch;
	FortyTwo<int> i;

	cout << ch.Get() << endl;
	cout << i.Get() << endl;
	return 0;
}
