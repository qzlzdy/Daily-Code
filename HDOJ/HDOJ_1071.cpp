#include<iostream>
#include<iomanip>
#include<ios>
using namespace std;
double k,m,a,b,c;
double xPos[3],yPos[3];
double getValue(){
    double x = xPos[2],y=xPos[1];
    double rs1 = a / 3 * x*x*x + 0.5 *(b - k)* x*x +(c - m)*x;
    double rs2 = a / 3 * y*y*y + 0.5 *(b - k)* y*y +(c - m)*y;
    return rs1 - rs2;
}
int main(){
    int T;
    cin>>T;
    while(T > 0){
        for(int i = 0; i < 3; i++)
            cin>>xPos[i]>>yPos[i];
        k = (yPos[1] - yPos[2])/(xPos[1] - xPos[2]);
        m = (xPos[1] * yPos[2] - xPos[2] * yPos[1])/(xPos[1] - xPos[2]);
        double van = 1;
        for(int i = 0; i < 2; i++)
            for(int j = i + 1; j < 3; j++)
                van *= xPos[i] - xPos[j];
        a = ((yPos[1] - yPos[0])*(xPos[2] - xPos[0]) - (xPos[1] - xPos[0])*(yPos[2] - yPos[0]))/van;
        b = ((xPos[1]*xPos[1] - xPos[0]*xPos[0])*(yPos[2] - yPos[0]) - (xPos[2]*xPos[2] - xPos[0]*xPos[0])*(yPos[1] - yPos[0]))/van;
        c = yPos[0] - a * xPos[0] * xPos[0] - b * xPos[0];
        cout<<fixed<<setprecision(2)<<getValue()<<endl; 
        T--;
    }
    return 0;
}
