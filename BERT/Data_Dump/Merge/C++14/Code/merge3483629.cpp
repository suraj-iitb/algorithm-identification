#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;

void merge(vector<int>& A, int left, int mid, int right, int&counter) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1 + 1);
  vector<int> R(n2 + 1);
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  L[n1] = inf;
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  R[n2] = inf;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    counter++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
};

void mergeSort(vector<int>& A, int left, int right, int& counter) {
  if (right - left > 1) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid, counter);
    mergeSort(A, mid, right, counter);
    merge(A, left, mid, right, counter);
  }
}

int main() {
  int n;
  cin >> n;
  int counter = 0;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  mergeSort(A, 0, n, counter);
  for (int i = 0; i < n; i++) {
    if (i < n - 1) {
      cout << A[i] << ' ';
    } else {
      cout << A[i] << endl;
    }
  }
  cout << counter << endl;
};

