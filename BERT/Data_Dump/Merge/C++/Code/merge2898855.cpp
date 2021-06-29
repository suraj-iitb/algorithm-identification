#include <iostream>
using namespace std;
 
#define MAX 500000
#define SENTINEL 1000000000
 
int L[MAX/2+1], R[MAX/2+1];
int cnt;
 
void merge(int A[], int left, int right, int mid){
  int n1 = mid - left;
  int n2 = right - mid;
  for(int i=0;i<n1;i++) L[i] = A[left + i];
  for(int i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  int i = 0, j = 0;
  for(int k=left;k<right;k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}
 
void mergeSort(int A[], int left, int right){
  if(right - left > 1){
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, right, mid);
  }
}
 
int main(){
  int n;
  cin >> n;
  int S[MAX];
  for(int i=0;i<n;i++){
    cin >> S[i];
  }
  mergeSort(S, 0, n);
  for(int i=0;i<n;i++){
    if(i != n-1) cout << S[i] << " ";
    else cout << S[i] << endl;
  }
  cout << cnt << endl;
  return 0;
}

