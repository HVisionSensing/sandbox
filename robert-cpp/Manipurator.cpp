/**
 * @file Manipurator.cpp
 */
#include <iostream>
#include <iomanip> // マニュピュレータを使うために必要
using namespace std;

int main() {
	char buf[] = "hello";

	// printf("%02X", buf[count]); と同等の処理
	for (int count = 0; count < sizeof(buf)/sizeof(*buf); count++) {
		cout << setw(2) << setfill('0') << hex << uppercase << (int)buf[count] << ' ';
	}
	cout << endl;
	return 0;
}
