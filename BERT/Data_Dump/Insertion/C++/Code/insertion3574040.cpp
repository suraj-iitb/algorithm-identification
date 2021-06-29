#include<iostream>
#include<algorithm>
using namespace std;
void print(int A[],int N)
{
    for(int i=0;i<N;i++)
    {
        if(i>0)
        {
            cout<<" ";
        }
        cout<<A[i];
    }
    cout<<endl;
}
void insertsort(int A[],int N)
{
    int temp,i,j;
    for(i=1;i<N;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0&&A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
        print(A,N);
    }
}
int main()
{
    int n,i,j;
    int a[105];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    print(a,n);
    insertsort(a,n);
    return 0;
}
