#include<iostream>
using namespace std;
static const int INF = 1000000001;

int cmp = 0;

void merge(int *A, int left, int mid, int right){
  int n1 = mid -left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];
  for(int i=0; i<n1; i++) L[i] = A[left + i];
  for(int i=0; i<n2; i++) R[i] = A[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  int i=0, j=0;
  for(int k=left; k<right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i++];
      cmp++;
    }else{
      A[k] = R[j++];
      cmp++;
    }
  }
  return;
}

void mergeSort(int *A, int left, int right){
  if(left+1 < right){
    int mid = (left+right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  return;
}

int main(){
  int n, A[500000];
  cin >> n;
  for(int i=0; i<n; i++) cin >> A[i];

  mergeSort(A, 0, n);
  for(int i=0; i<n; i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl << cmp << endl;
  return 0;
}

