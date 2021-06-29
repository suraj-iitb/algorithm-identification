#include<iostream>
using namespace std;
#define INFTY 2000000000
int count=0;
void merge(int A[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int *L=new int[n1+1];
  int *R=new int[n2+1];
  for(int i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=INFTY;
  R[n2]=INFTY;
  int i=0;
  int j=0;
  for(int k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
    count++;
  }
  delete[] L;
  delete[] R;
}
void mergeSort(int A[],int left,int right){
  if(left+1>=right)
    return;
  int mid=(left+right)/2;
  mergeSort(A,left,mid);
  mergeSort(A,mid,right);
  merge(A,left,mid,right);
}

int main(){
  int n;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  mergeSort(A,0,n);
  for(int i=0;i<n-1;i++){
    cout<<A[i]<<' ';
  }
  cout<<A[n-1]<<endl;
  cout<<count<<endl;
}

