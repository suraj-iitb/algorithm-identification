#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];

    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

    for(int i=0; i<n; i++)
    {
        if(i==n-1)
            cout<<A[i];
        else
            cout<<A[i]<<" ";
    }
    cout<<"\n";

    for(int i =1; i<n; i++)
    {
        int key;
        key = A[i];
        int j = i - 1;
        while( j >= 0 and A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;

        for(int i=0; i<n; i++)
        {
            if(i==n-1)
                cout<<A[i];
            else
                cout<<A[i]<<" ";
        }
        cout<<"\n";
    }
}

