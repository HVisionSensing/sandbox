/**
 * @file Fraction.cpp
 */
#include <iostream>
using namespace std;

class Fraction {
public:
	Fraction(double numer = 0, double denom = 1) :
		m_numer(numer), m_denom(denom) {};
	Fraction(const Fraction& f) {
		m_numer = f.m_numer;
		m_denom = f.m_denom;
	}
	virtual ~Fraction() {};

#if 0
	// doubleキャストのオーバーロード
	operator double() const {
		return m_numer / m_denom;
	}
#endif

	// 代入演算
	Fraction operator=(const Fraction &f) {
		m_numer = f.m_numer;
		m_denom = f.m_denom;
	}

	// 四則演算
	Fraction operator+(const Fraction& f) {
		return Fraction(m_numer * f.m_denom + m_denom * f.m_numer,
						m_denom * f.m_denom);
	}
	Fraction operator-(const Fraction &f) {
		return this->operator+(Fraction(-1, 1) * f);
		// operator+(f * Fraction(-1, 1)) では上手く行かない...
	}
	Fraction operator*(const Fraction &f) {
		return Fraction(m_numer * f.m_numer, m_denom * f.m_denom);
	}
	Fraction operator/(const Fraction &f) {
		return this->operator*(Fraction(f.m_denom, f.m_numer));
	}

	// double値との四則演算. ここでは d * f の場合のみ考慮する.
	// (f * d の場合はdがFraction型へ暗黙的にキャストされるため問題ない)

	// ただし左項（最も左にある引数）dの型がFractionではないためメンバ関数にはできない
	// そこで左項のdも引数に取り込んで非メンバ関数化する

	// 非メンバ関数化するとFractionのprivateメンバにアクセスできないため、
	// friend宣言することでそれらのメンバにアクセス可能とする

	friend Fraction operator+(double d, const Fraction& f) {
		return Fraction(d * f.m_denom + f.m_numer, f.m_denom);
	}
	friend Fraction operator-(double d, const Fraction& f) {
		return Fraction(d * f.m_denom - f.m_numer, f.m_denom);
	}
	friend Fraction operator*(double d, const Fraction& f) {
		return Fraction(d * f.m_numer, f.m_denom);
	}
	friend Fraction operator/(double d, const Fraction& f) {
		return Fraction(d * f.m_denom, f.m_numer);
	}

	friend ostream& operator<<(ostream& out, const Fraction& f) {
		return out << f.m_numer << "/" << f.m_denom;
	}

private:
	double m_numer;
	double m_denom;
};


int main() {
	Fraction f1 = Fraction(1,2);
	Fraction f2 = Fraction(1,3);
	double d = 4.0;

	cout << "f1 = " << f1 << endl;
	cout << "f2 = " << f2 << endl;
	cout << " d = " << d << endl;
	cout << endl;

	cout << "f1 + f2 = " << (f1 + f2) << endl;
	cout << "f1 - f2 = " << (f1 - f2) << endl;
	cout << "f1 * f2 = " << (f1 * f2) << endl;
	cout << "f1 / f2 = " << (f1 / f2) << endl;
	cout << " d + f2 = " << (d + f2) << endl;
	cout << " d - f2 = " << (d - f2) << endl;
	cout << " d * f2 = " << (d * f2) << endl;
	cout << " d / f2 = " << (d / f2) << endl;

	return 0;
}
