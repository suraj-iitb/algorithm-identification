#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int count=0;
    cin>>n;

    int A[100];
    for(int i=0;i<n;i++)
        cin>>A[i];


    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        swap(A[i],A[minj]);
        if(i!=minj)
            count++;
    }

    for(int i=0;i<n-1;i++) {
        cout<<A[i]<<" ";
    }
    cout<<A[n-1]<<endl<<count<<endl;

    return 0;
}

