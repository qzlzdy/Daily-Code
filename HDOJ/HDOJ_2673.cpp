#include<iostream>
using namespace std;
int partition(int *input,int begin,int end)
{
    int i = begin,j = end - 1,key = input[end - 1];
    while(i < j)
    {
        if(input[i] > key)
        {
            int temp = input[i];
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
void quickSort(int *input,int begin,int end)
{
    if(end - begin > 1)
    {
        int mid = partition(input,begin,end);
        quickSort(input,begin,mid);
        quickSort(input,mid + 1,end);
    }
}
int main(){
    int N;
    while(cin>>N)
    {
        int arr[N];
        for(int i = 0; i < N; i++)
            cin>>arr[i];
        quickSort(arr,0,N);
        cout<<arr[N - 1];
        int i = 0,j = N - 2;
        while(i < j)
        {
            cout<<" "<<arr[i++];
            if(i == j)
                break;
            cout<<" "<<arr[j--];
        }
        cout<<" "<<arr[i]<<endl;
    } 
    return 0;
}