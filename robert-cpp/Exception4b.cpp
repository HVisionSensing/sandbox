/**
 * @file Execption4b.cpp
 */
#include <iostream>
using namespace std;

void Error() {
	int *p = NULL;

	try {
		p = new int(10);
		throw "エラー発生！";
		delete[] p;
	} catch(...) {
		cerr << "メモリを解放します。" << endl;
		delete[] p;
		throw; // "エラー発生！"がそのままthrowされる
	}
}

int main() {
	try {
		Error();
	} catch(const char* error) {
		cerr << error << endl;
	}
	return 0;
}

		
