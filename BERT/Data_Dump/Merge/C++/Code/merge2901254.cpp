#include<iostream>

using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

int merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = SENTINEL;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}
   
int mergeSort(int A[], int left, int right){
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
   
int main() {
  int A[MAX], N;

  cnt = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  mergeSort(A, 0, N);

  for (int i = 0; i < N; i++) {
    if (i) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;

  cout << cnt << endl;

  return 0;
}

