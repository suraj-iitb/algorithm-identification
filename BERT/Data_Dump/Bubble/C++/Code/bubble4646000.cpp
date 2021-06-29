#include<iostream>
using namespace std;
int bubbleSort(int a[],int n)
{
    int flag=1,i,temp,c=0;
    while(flag)
    {
        flag=0;
        for(i=n-1;i>=1;i--)
        {
            if(a[i]<a[i-1])
            {
                temp=a[i];
                a[i]=a[i-1];
                a[i-1]=temp;
                c++;
                flag=1;
            }
        }
    }
    return c;
}
int main()
{
    int N,A[101];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    int num=bubbleSort(A,N);
    for(int i=0;i<N;i++)
    {
        if(i>0)
            cout<<" ";
        cout<<A[i];
    }
    cout<<endl<<num<<endl;

    return 0;
}

