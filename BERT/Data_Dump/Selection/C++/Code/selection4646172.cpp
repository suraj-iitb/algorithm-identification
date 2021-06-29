#include<iostream>
using namespace std;
int selectionSort(int a[],int n)
{
    int i,j,minj,num=0;
    for(i=0;i<n;i++)
    {
        minj=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<a[minj])
            {
                minj=j;
            }
        }
        swap(a[i],a[minj]);
        if(i==minj)
            continue;
        num++;
    }
    return num;
}
int main()
{
    int N,A[101];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    int num=selectionSort(A,N);
    for(int i=0;i<N;i++)
    {
        if(i)
            cout<<" ";
        cout<<A[i];
    }
    cout<<endl<<num<<endl;
    return 0;
}

