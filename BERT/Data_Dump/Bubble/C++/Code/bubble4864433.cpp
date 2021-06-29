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

int bubbleSort(int A[],int N)
{
    int flag=1;
    int count=0;
    int location=0;
    while(flag)
    {
        flag=0;
        for(int j=N-1;j>=location+1;j--)
        {
            if(A[j]<A[j-1])
            {
                swap(A[j],A[j-1]);
                count++;
                flag=1;
            }
        }
        location++;
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
    int ans=bubbleSort(A,n);
    printArray(A,n);
    cout<<endl<<ans<<endl;
    return 0;
}

