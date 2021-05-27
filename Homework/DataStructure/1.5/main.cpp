#include <iostream>
#include "Polynomial.h"
using namespace std;

int main(){
	Polynomial P,Q;
	float x;
	cout<<"Input polynomial P & Q."<<endl;
	while(cin>>P>>Q){

		//测试输入输出
		cout<<"P: "<<P<<endl;
		cout<<"Q: "<<Q<<endl;

		cout<<"P + Q: "<<P + Q<<endl;	//测试多项式加法
		cout<<"P - Q: "<<P - Q<<endl;	//测试多项式减法
		cout<<"P * Q: "<<P * Q<<endl;	//测试多项式乘法
		cout<<"Derivative: "<<P.derivative()<<endl;	//测试求导

		//测试求x处值
		cout<<"Input the value of x."<<endl;
		cin>>x;
		cout<<"Value at "<<x<<": "<<P(x)<<endl;

		//准备下次循环
		cout<<"Input polynomial P & Q."<<endl;
	}
}
