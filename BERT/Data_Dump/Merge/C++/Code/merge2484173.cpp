#include <iostream>
#include <math.h>
#define MAX 500000
using namespace std;
 
void merge(int[],int,int,int,int);
void mergeSort(int[],int,int,int);
int L[MAX/2+2],R[MAX/2+2];
int cnt;
 
int main(){
  int i,n;
  cnt = 0;
  int A[MAX];
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> A[i];
  }
  mergeSort(A,n,0,n);
  for(i = 0; i < n; i++){
    if(0 < i){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl; 
  cout << cnt; 
  cout << endl;
  
  return 0;
}
void merge(int A[],int n,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0,j = 0;
  for(k = left; k < right; k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}
void mergeSort(int A[], int n, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}
