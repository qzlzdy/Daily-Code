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
	friend istream& operator>>(istream& in,Polynomial& P);	//�����빹�����ʽ O(n2)
	friend ostream& operator<<(ostream& out,const Polynomial& P);	//�������ʽ O(n)
	float operator()(float x);	//�������ʽ��x����ֵ O(n)
	Monomial& operator[](int i)const;	//���ص�i������ʽ O(n)
	Polynomial operator+(Polynomial& P);	//����ʽ�ӷ� O(n)
	Polynomial operator-(Polynomial& P);	//����ʽ���� O(n)
	Polynomial operator*(Polynomial& P);	//����ʽ�˷� O(n2)
	Polynomial derivative();	//�� O(n)
	void insertMonomial(Monomial* P);	//���뵥��ʽ O(n)
	void deleteMonomial(Monomial* P);	//ɾ������ʽ O(1)
	void clear();	//��յ���ʽ O(n)
private:
	Monomial* head;
	int _size;
};

#endif /* POLYNOMIAL_H_ */
