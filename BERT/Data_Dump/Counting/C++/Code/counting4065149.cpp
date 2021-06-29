#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)


/*int B[10010],C[10010];
    int n;
void countsort(int A[],int B[],int k){
    rep(i,0,k+1)C[i]=0;
    rep(j,0,n)C[A[j]]++;
    rep(i,1,k+1)C[i]=C[i]+C[i-1];
    for(int j=n-1;j>=0;j++){
        B[C[A[j]]]=A[j];
        C[A[j]];
    }
}*/



int main(){
    int n;
    int A[2000010],B[2000010],C[10010];
    cin>>n;
    int k=10000;
    rep(i,0,n)cin>>A[i];
    rep(i,0,k+1)C[i]=0;
    rep(j,0,n)C[A[j]]++;
    rep(i,1,k+1)C[i]=C[i]+C[i-1];
    for(int j=n-1;j>=0;j--){
        C[A[j]]--;
                B[C[A[j]]]=A[j];

    }    rep(i,0,n){
        if(i)cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
}



