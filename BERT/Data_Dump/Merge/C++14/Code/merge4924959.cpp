#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&A,int l,int mid,int r,int&cnt){
  int n1=mid-l,n2=r-mid;
  vector<int64_t>L(n1+1),R(n2+1);
  for(int i=0;i<n1;i++){
    L[i]=A[l+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L.back()=INT_MAX,R.back()=INT_MAX;
  for(int i=0,j=0,k=l;k<r;k++){
    cnt++;
    if(L[i]<=R[j])A[k]=L[i++];
    else A[k]=R[j++];
  }
  return;
}

void mgst(vector<int>&A,int l,int r,int&cnt){
  if(l+1<r){
    int mid=(l+r)/2;
    mgst(A,l,mid,cnt);
    mgst(A,mid,r,cnt);
    merge(A,l,mid,r,cnt);
  }
  return;
}

int main(){
  int cnt=0,n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  mgst(a,0,n,cnt);
  for(int i=0;i<n;i++)cout<<a[i]<<(i==n-1?'\n':' ');
  cout<<cnt<<endl;
}
