#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial(){
	_size = 0;
	head = new Monomial(0,0);
	head->next = head->prev = head;
}

Polynomial::~Polynomial(){
	clear();
	delete head;
}

const Polynomial& Polynomial::operator =(const Polynomial& P){
	clear();
	Monomial* p = P.head->next;
	for(int i = 0; i < P._size; i++){
		insertMonomial(new Monomial(p->coe,p->ind));
		p = p->next;
	}
	return P;
}

istream& operator>>(istream& in,Polynomial& P){
	P.clear();
	int ind,n = 0;
	float coe;
	cin>>n;
	while(n--){
		in>>coe>>ind;
		if(coe != 0)
			P.insertMonomial(new Monomial(coe,ind));
	}
	return in;
}

ostream& operator<<(ostream& out,const Polynomial& P){
	if(P._size == 0){
		out<<"0";
		return out;
	}
	for(int i = 1; i <= P._size; i++){
		//��1�����⴦��
		if(i != 1 && P[i].coe > 0)
			out<<"+";

		//���������⴦���ǳ�����ʡ��1
		if(P[i].ind == 0 || (P[i].coe != 1 && P[i].coe != -1))
			out<<P[i].coe;
		else if(P[i].coe == -1)
			out<<"-";

		//���ָ��
		if(P[i].ind != 0){
			out<<"x";
			if(P[i].ind != 1)
				out<<"^"<<P[i].ind;
		}
	}
	return out;
}

float Polynomial::operator ()(float x){
	float sum = 0;
	Monomial* p = head->next;

	//�����������ʽ��ֵ
	while(p != head){
		sum += p->coe * pow(x,p->ind);
		p = p->next;
	}
	return sum;
}

Monomial& Polynomial::operator [](int i)const{
	Monomial *p = head->next;
	for(int k = 1; k < i; k++)
		p = p->next;
	return *p;
}

Polynomial Polynomial::operator +(Polynomial& P){
	Polynomial R;
	Monomial* p = P.head->next;
	Monomial* q = head->next;

	//������ͬ����ӣ�������ֱͬ�Ӳ���
	while(p != P.head && q != head){
		if(p->ind == q->ind){
			if(p->coe + q->coe != 0)
				R.insertMonomial(new Monomial(p->coe + q->coe,p->ind));
			p = p->next;
			q = q->next;
		}else if(p->ind > q->ind){
			R.insertMonomial(new Monomial(p->coe,p->ind));
			p = p->next;
		}else{
			R.insertMonomial(new Monomial(q->coe,q->ind));
			q = q->next;
		}
	}
	//��P������
	while(p != P.head){
		R.insertMonomial(new Monomial(p->coe,p->ind));
		p = p->next;
	}
	//��*this������
	while(q != head){
		R.insertMonomial(new Monomial(q->coe,q->ind));
		q = q->next;
	}
	return R;
}

Polynomial Polynomial::operator -(Polynomial& P){
	//ͬ�ӷ�ԭ��
	Polynomial R;
	Monomial* p = P.head->next;
	Monomial* q = head->next;
	while(p != P.head && q != head){
		if(p->ind == q->ind){
			if(p->coe - q->coe != 0)
				R.insertMonomial(new Monomial(q->coe - p->coe,p->ind));
			p = p->next;
			q = q->next;
		}else if(p->ind > q->ind){
			R.insertMonomial(new Monomial(-p->coe,p->ind));
			p = p->next;
		}else{
			R.insertMonomial(new Monomial(q->coe,q->ind));
			q = q->next;
		}
	}
	while(p != P.head){
		R.insertMonomial(new Monomial(-p->coe,p->ind));
		p = p->next;
	}
	while(q != head){
		R.insertMonomial(new Monomial(q->coe,q->ind));
		q = q->next;
	}
	return R;
}

Polynomial Polynomial::operator *(Polynomial& P){
	Polynomial R;
	Monomial* q = head->next;

	//���ν�*this��ÿһ�����P��ÿһ��
	while(q != head){
		for(int i = 1; i <= P._size; i++)
			R.insertMonomial(new Monomial(q->coe * P[i].coe,q->ind + P[i].ind));
		q = q->next;
	}
	return R;
}

Polynomial Polynomial::derivative(){
	Polynomial Q;
	Monomial* p = head->next;
	while(p != head){
		if(p->ind != 0)
			Q.insertMonomial(new Monomial(p->coe * p->ind,p->ind - 1));
		p = p->next;
	}
	return Q;
}

void Polynomial::insertMonomial(Monomial* P){
	Monomial* Q = head->next;
	//��λ
	while(Q != head && Q->ind > P->ind)
		Q = Q->next;
	//���ϲ�ͬ�����ϵ��Ϊ����ɾ���õ���ʽ
	if(Q != head && Q->ind == P->ind){
		Q->coe += P->coe;
		if(Q->coe == 0)
			deleteMonomial(Q);
	}else{
		P->next = Q;
		P->prev = Q->prev;
		Q->prev->next = P;
		Q->prev = P;
		_size++;
	}
}

void Polynomial::deleteMonomial(Monomial* P){
	P->prev->next = P->next;
	P->next->prev = P->prev;
	_size--;
	delete P;
}

void Polynomial::clear(){
	while(_size != 0)
			deleteMonomial(head->next);
}
