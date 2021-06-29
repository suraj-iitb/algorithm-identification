#include<bits/stdc++.h>
using namespace std;
int n,cnt;
void merge(vector<int>&A,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  vector<int>L(n1+1),R(n2+1);
  for(int i=0;i<n1;i++)L[i]=A[left+i];
  for(int i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=1<<30;
  R[n2]=1<<30;
  int i=0,j=0;
  for(int k=left;k<right;k++){
    if(L[i]<=R[j])A[k]=L[i++];
    else A[k]=R[j++];
    cnt++;
  }
}
void mergeSort(vector<int>&A,int left,int right){
  if(1<right-left){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
int main(void){
  cin>>n;
  vector<int>A(n);
  for(int i=0;i<n;i++)cin>>A[i];
  mergeSort(A,0,n);
  for(int i=0;i<n;i++)cout<<A[i]<<" \n"[i==n-1];
  cout<<cnt<<endl;
  return 0;
}

