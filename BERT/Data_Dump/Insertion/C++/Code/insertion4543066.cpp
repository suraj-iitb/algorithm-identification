#include<iostream>
using namespace std;

void trace(int A[], int N)
{
    for(int i=0; i<N-1; i++)cout<<A[i]<<' ';
    cout<<A[N-1]<<endl;
}

void insertionSort(int A[], int N)
{
    for(int i=1; i<N; i++)
    {
        int j = i-1;
        int k = A[i];
        while(j>=0 && A[j]>k)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = k;
        trace(A,N);
    }
}

int main()
{
    int N,A[110];

    cin>>N;
    for(int i=0; i<N; i++)cin>>A[i];

    trace(A,N);
    insertionSort(A,N);

    return 0;
}

