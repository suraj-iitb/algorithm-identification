#include <bits/stdc++.h>
using namespace std;
const int INFTY = 2000000000;

long long cnt = 0;

void merge(vector<int> &A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1+1), R(n2+1);
  for (int i = 0; i <= n1; i++) {
    L[i] = A[left + i];
  }
  for (int j = 0; j <= n2; j++) {
    R[j] = A[mid + j];
  }
  L[n1] = R[n2] = INFTY;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(vector<int> &A, int left, int right) {
  if (right - left > 1) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  mergeSort(A, 0, n);
  
  for (int i = 0; i < n; i++) {
    if (i) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
}