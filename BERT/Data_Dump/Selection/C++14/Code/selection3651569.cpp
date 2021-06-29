#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=j;i<n;i++)
int selectionsort(int A[],int n){
    int x=0;
    rep(i,0,n-1){
        int minv=i;
        rep(j,i+1,n){
            if(A[minv]>A[j])minv=j;
        }
        if(minv!=i){
            swap(A[i],A[minv]);
            x++;
        }   
    }
    return x;
}
int main(){
    int n;cin>>n;
    int A[n];
    rep(i,0,n)cin>>A[i];
    int ans=selectionsort(A,n);
    rep(i,0,n-1)cout<<A[i]<<" ";
    cout<<A[n-1]<<endl;
    cout<<ans<<endl;
}
