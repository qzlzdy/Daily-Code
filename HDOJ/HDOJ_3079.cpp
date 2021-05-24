#include<iostream>
#include<cctype>
using namespace std;
int main(){
    int T;
    cin>>T;
    char str[51];
    while(T > 0)
    {
        cin>>str;
        for(int i = 0; i < 50; i++)
        {
            switch(str[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    str[i] = toupper(str[i]);
                    break;
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    break;
                default:
                     str[i] = tolower(str[i]);
            }
        }
        cout<<str<<endl;
        T--;
    }
    return 0;
}