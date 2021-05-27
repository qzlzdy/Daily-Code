#include <iostream>
#include "Polynomial.h"
using namespace std;

int main(){
	Polynomial P,Q;
	float x;
	cout<<"Input polynomial P & Q."<<endl;
	while(cin>>P>>Q){

		//�����������
		cout<<"P: "<<P<<endl;
		cout<<"Q: "<<Q<<endl;

		cout<<"P + Q: "<<P + Q<<endl;	//���Զ���ʽ�ӷ�
		cout<<"P - Q: "<<P - Q<<endl;	//���Զ���ʽ����
		cout<<"P * Q: "<<P * Q<<endl;	//���Զ���ʽ�˷�
		cout<<"Derivative: "<<P.derivative()<<endl;	//������

		//������x��ֵ
		cout<<"Input the value of x."<<endl;
		cin>>x;
		cout<<"Value at "<<x<<": "<<P(x)<<endl;

		//׼���´�ѭ��
		cout<<"Input polynomial P & Q."<<endl;
	}
}
