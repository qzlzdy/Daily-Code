#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include "Monomial.h"
#include <iostream>
using namespace std;

class Polynomial {
public:
	Polynomial();	//O(1)
	~Polynomial();	//O(n)
	const Polynomial& operator=(const Polynomial& P);	//O(n2)
	friend istream& operator>>(istream& in,Polynomial& P);	//从输入构造多项式 O(n2)
	friend ostream& operator<<(ostream& out,const Polynomial& P);	//输出多项式 O(n)
	float operator()(float x);	//计算多项式在x处的值 O(n)
	Monomial& operator[](int i)const;	//返回第i个单项式 O(n)
	Polynomial operator+(Polynomial& P);	//多项式加法 O(n)
	Polynomial operator-(Polynomial& P);	//多项式减法 O(n)
	Polynomial operator*(Polynomial& P);	//多项式乘法 O(n2)
	Polynomial derivative();	//求导 O(n)
	void insertMonomial(Monomial* P);	//插入单项式 O(n)
	void deleteMonomial(Monomial* P);	//删除单项式 O(1)
	void clear();	//清空单项式 O(n)
private:
	Monomial* head;
	int _size;
};

#endif /* POLYNOMIAL_H_ */
