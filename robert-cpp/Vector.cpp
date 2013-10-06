/**
 * @file Vector.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;

template <typename TYPE> class Vector {
public:
	Vector(TYPE n) {
		m_size = n;
		m_array = new TYPE(n);
	}
	Vector(const Vector &v) {
		m_size = v.m_size;
		m_array = new TYPE(m_size);
		copy(v.m_array, v.m_array + m_size, m_array);
	}
	virtual ~Vector() {
		delete[] m_array;
	}
	TYPE& operator[](int index) {
		return m_array[index];
	}
	
private:
	TYPE* m_array;
	int m_size;
};

int main() {
	Vector<int> v(4);
	v[3] = 3;
	cout << "v[3] = " << v[3] << endl;
	return 0;
}
