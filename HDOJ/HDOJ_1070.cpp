#include<iostream>
#include<cstdio>
#include<iomanip>

using namespace std;

int main(){
    int N;
    cin>>N;
    while(N > 0){
        char oper;
        int a,b;
        cin>>oper>>a>>b;
        switch(oper){
        case '+':
            printf("%d\n",a + b);
            break;
        case '-':
            printf("%d\n",a - b);
            break;
        case '*':
            printf("%d\n",a * b);
            break;
        case '/':
            double quo = 1.0 * a / b;
            if(quo != a / b)
                printf("%.2f\n",quo);
            else
                printf("%d\n",a / b);;
            break;
        }
        N--;
    } 
    return 0;
}

