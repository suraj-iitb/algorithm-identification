#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s=0,n,A[99];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>=i+1; j--)
        {
            if(A[j]<A[j-1])
            {
                swap(A[j],A[j-1]);
                s++;
            }
        }
    }
    for(int k=0; k<n; k++)
    {
        cout<<A[k];
        if(k<n-1)
        {
            cout<<" ";
        }
    }
    cout<<endl<<s<<endl;
  return 0;
}
