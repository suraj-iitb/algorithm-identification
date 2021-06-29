#include <iostream>
#include <algorithm>
#define MAX 500000
#define INFTY 2000000000
using namespace std;

int L[MAX/2+2],R[MAX/2+2];
int cnt;

void merge(int A[],int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){L[i]=A[left+i]; }
  for(i=0;i<n2;i++){R[i]=A[mid+i]; }
  L[n1]=R[n2]=INFTY;

  i=j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j])A[k]=L[i++];
    else A[k]=R[j++];
  }  

}

void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int A[MAX];
  int n,i;

  cin >> n;
  for(i=0;i<n;i++){cin >> A[i]; }
  mergeSort(A,0,n);

  for(i=0;i<n-1;i++){cout << A[i] << " ";}
  cout << A[i] << endl;
  cout << cnt << endl;
  
  return 0;
}

