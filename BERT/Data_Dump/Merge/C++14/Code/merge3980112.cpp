#include <bits/stdc++.h>
using namespace std;

int count_num;

void Merge(int* A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int array_l[n1 + 1];
  int array_r[n2 + 1];
  for (int i = 0; i < n1; i++) {
    array_l[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    array_r[i] = A[mid + i];
  }
  array_l[n1] = INT_MAX;
  array_r[n2] = INT_MAX;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (array_l[i] <= array_r[j]) {
      A[k] = array_l[i];
      i = i + 1;
    } else {
      A[k] = array_r[j];
      j = j + 1;
    }
    count_num++;
  }
}

void MergeSort(int* A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  MergeSort(A, 0, n);
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << A[i];
  }
  cout << endl << count_num << endl;
  return 0;
}
