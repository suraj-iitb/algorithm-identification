#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=j;i<n;i++)
int bubblesort(int A[],int N){
    int C=0;
    rep(i,0,N){
        for(int j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
                int v=A[j];
                A[j]=A[j-1];
                A[j-1]=v;
                C++;
            }
        }
    }
    return C;
}
int main(){
    int n;cin>>n;
    int A[n];int ans;
    rep(i,0,n)cin>>A[i];
    ans=bubblesort(A,n);
    rep(i,0,n-1)cout<<A[i]<<" ";
    cout<<A[n-1]<<endl;
    cout<<ans<<endl;
    
}
