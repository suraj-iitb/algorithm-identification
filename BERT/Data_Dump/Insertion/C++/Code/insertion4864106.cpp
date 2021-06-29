#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int A[],int N)
{
    for(int i=0;i<N;i++)
    {
        if(i==N-1)
            cout<<A[i]<<endl;
        else
            cout<<A[i]<<" ";
    }
}

void insertSort(int A[],int N)
{
    int j,p;
    int temp;
    for(p=1;p<N;p++)
    {
        temp=A[p];
        for(j=p;j>0&&A[j-1]>temp;j--)
        {
            A[j]=A[j-1];
        }
        A[j]=temp;
        printArray(A,N);
    }
}

int main()
{
    int n;
    cin>>n;
    int A[100];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    printArray(A,n);
    insertSort(A,n);
    return 0;
}

