/**
 * @file MemFuncPointer.cpp
 */
#include <iostream>
using namespace std;

class Calculator {
	typedef int (Calculator::*FuncPtr)(); // メンバ関数ポインタの型定義
	struct Operator {
		const char* name;
		FuncPtr func;
	};
	static const Operator FP_OPERATORS[];

public:
	void Run();

private:
	int m_a, m_b;
	int Add() { return m_a + m_b; }
	int Sub() { return m_a - m_b; }
	int Mul() { return m_a * m_b; }
	int Div() { return m_a / m_b; }

	bool Input();
	void Calculate();
};

const Calculator::Operator Calculator::FP_OPERATORS[] = {
	// メンバ関数のポインタを代入していく
	{"Add", &Calculator::Add},
	{"Sub", &Calculator::Sub},
	{"Mul", &Calculator::Mul},
	{"Div", &Calculator::Div},
};

void Calculator::Run() {
	while(Input()) {
		Calculate();
	}
}

bool Calculator::Input() {
	cout << "input a pair of values > " << flush;
	m_b = 0;
	cin >> m_a >> m_b;
	return m_b != 0;
}

void Calculator::Calculate() {
	for (int i = 0; i < sizeof(FP_OPERATORS)/sizeof(*FP_OPERATORS); i++) {
		const Calculator::Operator* op = &(this->FP_OPERATORS[i]);
		int result = (this->*(op->func))(); // メンバ関数の呼び出し。this->*は省略不可
		cout << op->name << " : " << result << endl;
	}
}

int main() {
	Calculator calc;
	calc.Run();
	return 0;
}


