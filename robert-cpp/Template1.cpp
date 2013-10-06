/**
 * @file Template1.cpp
 */
#include <iostream>
#include <cstring>
using namespace std;

template <typename TYPE>
TYPE Max(TYPE a, TYPE b) {
	cout << "Max<TYPE> is called" << endl;
	return (a > b) ? a : b;
}

// 関数テンプレートをオーバーロード
template <>
char* Max<char *>(char* a, char *b) {
	cout << "Max<char *> is called" << endl;
	return (strcmp(a, b) > 0) ? a : b;
}
template <>
const char* Max<const char *>(const char* a, const char *b) {
	cout << "Max<const char *> is called" << endl;
	return (strcmp(a, b) > 0) ? a : b;
}

int main() {
	char str1[] = "chao";
	char str2[] = "bye";

	cout << Max(9, 3) << endl;
	cout << Max(-1.0, 2.5) << endl;
	cout << Max(str1, str2) << endl;
	cout << Max("good moring", (const char *)str1) << endl;
	return 0;
}



