#include<iostream>
#include<queue> 
using namespace std;
struct wood{
    int l;
    int w;
};
int partition(struct wood *input,int begin,int end)
{
    int i = begin,j = end - 1;
    struct wood key = input[end - 1];
    while(i < j)
    {
        if(input[i].l > key.l)
        {
            struct wood temp = input[i];
            input[i] = input[--j];
            input[j] = temp;
        }
        else if(input[i].l == key.l && input[i].w > key.w)
        {
            struct wood temp = input[i];
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
void quickSort(struct wood *input,int begin,int end)
{
    if(end - begin > 1)
    {
        int mid = partition(input,begin,end);
        quickSort(input,begin,mid);
        quickSort(input,mid + 1,end);
    }
}
int main(){
    int T;
    cin>>T;
    while(T > 0)
    {
        int n,num = 0,prevW;
        cin>>n;
        struct wood w[n];
        for(int i = 0; i < n; i++)
            cin>>w[i].l>>w[i].w;
        quickSort(w,0,n);
        queue<struct wood> q;
        for(int i = 0; i < n; i++)
            q.push(w[i]);
        struct wood temp;
        while(n > 0)
        {
            num++;
            prevW = q.front().w;
            queue<struct wood> p;
            q.pop();
            n--;
            while(!q.empty())
            {
                temp = q.front();
                q.pop();
                if(temp.w >= prevW)
                {
                    prevW = temp.w;
                    n--;
                }
                else
                    p.push(temp);
            }
            q = p;
        }
        cout<<num<<endl;
        T--;
    }
    return 0;
}
