/**
 * @file Class1.cpp
 */
#include <iostream>
using namespace std;

const int MAX_NAME = 16;

class Student {
public:
	char name[MAX_NAME+1];
	int scoreJapanese;
	int scoreMath;
	int scoreEnglish;
	void Show();
};

void Student::Show() {
	cout << "Name     : " << name << endl
		 << "Japanese : " << scoreJapanese << endl
		 << "Math     : " << scoreMath << endl
		 << "English  : " << scoreEnglish << endl
		 << endl;

}

int main() {
	Student students[] = {
		{"Ichiro", 73, 98, 86,},
		{"Daisuke", 64, 45, 40,},
		{"Hideki", 76, 78, 69,},
	};
	int size = sizeof(students) / sizeof(*students);

	for (int key = 0; key < size; key++) {
		students[key].Show();
	}

	return 0;
}



	
