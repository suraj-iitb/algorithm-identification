#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=j;i<n;i++)
void insertionsort(int A[],int N){
    rep(i,1,N){
        int v=A[i];int j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        rep(k,0,N-1)cout<<A[k]<<" ";
        cout<<A[N-1]<<endl;
    }
}
int main(){
    int n;cin>>n;
    int A[n];
    rep(i,0,n)cin>>A[i];
    rep(i,0,n-1)cout<<A[i]<<" ";
    cout<<A[n-1]<<endl;
    insertionsort(A,n);
}
