/**
 * @file List.cpp
 */
#include <iostream>
#include <list>
using namespace std;

static const int DIR_FORWARD = 0;
static const int DIR_BACKWARD = 1;

template <typename T>
void Show(list<T>& lst, int dir = DIR_FORWARD) {
	typename list<T>::iterator itr;
	typename list<T>::iterator begin = lst.begin();
	typename list<T>::iterator end = lst.end();

	if (dir == DIR_BACKWARD) {
		for (--(itr = end); ; --itr) {
			cout << *itr << ' ';
			if (itr == begin) break;
		}
	} else {
		for (itr = begin; itr != end; ++itr) {
			cout << *itr << ' ';
		}
	}
	cout << endl;
}

int main() {
	list<int> lst;

	for (int i = 0; i < 5; ++i) lst.push_back(i);
	Show(lst);
	Show(lst, DIR_BACKWARD);

	for (int i = 5; i < 10; ++i) lst.push_front(i);
	Show(lst);

	lst.pop_back();
	lst.pop_back();
	lst.pop_front();
	Show(lst);

	return 0;
}

