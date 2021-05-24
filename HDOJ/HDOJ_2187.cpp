#include<iostream>
#include<iomanip>
#include<ios>
using namespace std;
struct rice{
    int p;
    int h;
};
int partition(struct rice *input,int begin,int end)
{
    int i = begin,j = end - 1;
    struct rice key = input[end - 1];
    while(i < j)
    {
        if(input[i].p > key.p)
        {
            struct rice temp = input[i];
            input[i] = input[--j];
            input[j] = temp;
        }
        else
            i++;
    }
    input[end - 1] = input[i];
    input[i] = key;
    return i;
}
void quickSort(struct rice *input,int begin,int end)
{
    if(end - begin > 1)
    {
        int mid = partition(input,begin,end);
        quickSort(input,begin,mid);
        quickSort(input,mid + 1,end);
    }
}
int main(){
    int C;
    cin>>C;
    while(C > 0)
    {
        int n,m;
        cin>>n>>m;
        struct rice r[m];
        double weight = 0;
        for(int i = 0; i < m; i++)
        {
            cin>>r[i].p>>r[i].h;
        }
        quickSort(r,0,m);
        int k = 0;
        while(n > 0)
        {
            if(n >= r[k].p)
            {
                n -= r[k].p;
                weight++;
                r[k].h--;
            }
            else
            {
                weight += 1.0*n/r[k].p;
                n = 0;
            }
            if(r[k].h == 0)
                k++;
        }
        cout<<fixed<<setprecision(2)<<weight<<endl;
        C--;
    }
    return 0;
}