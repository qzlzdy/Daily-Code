#ifndef MONOMIAL_H_
#define MONOMIAL_H_

class Monomial {
public:
	Monomial(float c,int i);
	float coe;	//系数
	int ind;	//指数
	Monomial *next,*prev;
};

#endif /* MONOMIAL_H_ */
