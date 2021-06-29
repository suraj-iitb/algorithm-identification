#include <iostream>
#include <cmath>

using namespace std;

int merge(int *A, int left, int mid, int right) {
  int comp = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];
  for(int i=0; i<n1; i++) L[i] = A[left + i];
  for(int i=0; i<n2; i++) R[i] = A[mid + i];

  L[n1] = pow(10, 9);
  R[n2] = pow(10, 9);

  int i = 0, j = 0;
  for(int k = left; k < right; k++) {
    comp++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
  return comp;
}

int mergeSort(int *A, int left, int right) {
  int comp = 0;
  if(left+1 < right) {
    int mid = (left+right)/2;
    comp += mergeSort(A, left, mid);
    comp += mergeSort(A, mid, right);
    comp += merge(A, left, mid, right);
  }
  return comp;
}

int main(){
  int n;
  cin >> n;
  int A[n];
  for(int i = 0; i < n; i++) cin >> A[i];

  int comp = mergeSort(A, 0, n);

  for(int i = 0; i < n; i++) {
    cout << A[i];
    if(i != n-1) cout << " ";
    else cout << endl;
  }
  cout << comp << endl;
  return 0;
}



