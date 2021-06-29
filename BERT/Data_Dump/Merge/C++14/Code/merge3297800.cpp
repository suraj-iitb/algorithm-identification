#include<bits/stdc++.h>
#define INFTY 1000000002
using namespace std;
int counts,A[500002],L[250002],R[250002],n;
void merge(int *,int,int);
void mergeSort(int *,int,int);

int main(){
  int i;
  counts=0;
  cin>>n;
  for(i=0;i<n;i++)cin>>A[i];
  
  mergeSort(A,0,n);
  
  for(i=0;i<n;i++)if(i==0)cout<<A[i]; else cout<<" "<<A[i];
  cout<<endl<<counts<<endl;;
}

void merge(int A[],int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
    counts++;
  }
}

void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int  mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

