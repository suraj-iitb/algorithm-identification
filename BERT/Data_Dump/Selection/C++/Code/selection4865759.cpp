#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int A[],int N)
{
    for(int i=0;i<N;i++)
    {
        if(i==N-1)
            cout<<A[i];
        else
            cout<<A[i]<<" ";
    }
}

int selectionSort(int A[],int N)
{
    int count=0;
    for(int i=0;i<N-1;i++)
    {
        int minj=i;
        for(int j=i;j<N;j++)
        {
            if(A[j]<A[minj])
                {
                    minj=j;
                }
        }
        swap(A[i],A[minj]);
        if(i!=minj) count++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int A[105];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int ans=selectionSort(A,n);
    printArray(A,n);
    cout<<endl<<ans<<endl;
    return 0;
}

