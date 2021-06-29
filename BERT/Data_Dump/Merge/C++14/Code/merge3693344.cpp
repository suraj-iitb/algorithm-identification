#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define MAX 500000
int cnt;
void merge(int A[],int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[MAX/2+2],R[MAX/2+2];
    rep(i,0,n1)L[i]=A[left+i];
    rep(i,0,n2)R[i]=A[mid+i];
    L[n1]=2000000000;R[n2]=2000000000;
    int i=0,j=0;
    rep(k,left,right){
        cnt++;
        if(R[i]>=L[j]){
            A[k]=L[j];
            j++;
        }
        else{
            A[k]=R[i];
            i++;
        }
    }
}
void mergesort(int A[],int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(A,n,left,mid);
        mergesort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}
int main(){
    int n;cnt=0;cin>>n;
    int A[n];
    rep(i,0,n)cin>>A[i];
    mergesort(A,n,0,n);
    rep(i,0,n-1)cout<<A[i]<<" ";
    cout<<A[n-1]<<endl;
    cout<<cnt<<endl;
    return 0;
}
