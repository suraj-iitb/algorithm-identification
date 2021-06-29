#include <iostream>

using namespace std;

#define INFTY 1000000000;

int ct = 0;

void merge(int* A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i, j;

  int* L = new int[n1+1];
  int* R = new int[n2+1];

  for (int i = 0; i < n1; i++) {
    L[i] = A[left+i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid+i];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
    ct++;
  }

  delete[] L;
  delete[] R;
}

void mergeSort(int* A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);

    merge(A, left, mid, right);
  }
}

int main() {
  int n = 0;
  int S[500000];

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  mergeSort(S, 0, n);

  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << S[i];
  }

  cout << endl << ct << endl;

  return 0;
}

