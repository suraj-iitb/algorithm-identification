#include<iostream>
using namespace std;
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i>0)
            cout<<" ";
        cout<<a[i];

    }
    cout<<endl;
}
void insertSort(int a[],int n)
{
    int i,j,v;
    for(i=1;i<n;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        print(a,n);
    }
}
int main()
{
    int N,A[101];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    print(A,N);
    insertSort(A,N);
    return 0;
}

