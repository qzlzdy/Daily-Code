#ifndef MONOMIAL_H_
#define MONOMIAL_H_

class Monomial {
public:
	Monomial(float c,int i);
	float coe;	//ϵ��
	int ind;	//ָ��
	Monomial *next,*prev;
};

#endif /* MONOMIAL_H_ */
