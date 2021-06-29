#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
static const int INF=2e9;
int cnt=0;

void merge(int A[],int left,int mid,int right){
    int n1=mid-left,n2=right-mid;
    int B[n1+1],C[n2+1];
    B[n1]=C[n2]=INF;
    rep(i,n1)B[i]=A[left+i];
    rep(i,n2)C[i]=A[mid+i];
    int j=0,k=0;
    for(int i=left;i<right;i++){
        cnt++;
        if(B[j]>C[k])A[i]=C[k++];
        else A[i]=B[j++];
    }
    return;
}

void mergesort(int A[],int left,int right){
    if(left+1>=right)return;
    int mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
    return;
}

int main(){
    int n;cin>>n;
    int A[n];
    rep(i,n)scanf("%d",&A[i]);
    mergesort(A,0,n);
    rep(i,n){
        if(i!=0)cout<<" ";
        cout<<A[i];
    }
    cout<<"\n"<<cnt<<"\n";
    return 0;
}
