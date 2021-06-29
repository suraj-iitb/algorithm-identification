#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define MAX 2000000
int A[MAX],B[MAX],C[MAX];
int k=10000;int n;
void countingsort(int A[],int B[]){
    rep(i,0,k+1)C[i]=0;
    rep(j,1,n+1)C[A[j]]++;
    rep(i,1,k+1)C[i]=C[i]+C[i-1];
    for(int i=1;i<=n;i++){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
}
int main(){
    cin>>n;
    rep(i,1,n+1)cin>>A[i];
    countingsort(A,B);
    rep(i,1,n){
        cout<<B[i]<<" ";
    }
    cout<<B[n]<<endl;
    return 0;
}
