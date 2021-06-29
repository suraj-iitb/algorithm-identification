#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

#define MAX_N 500000
#define INF 1000000005

int L[MAX_N / 2 + 5], R[MAX_N / 2 + 5];
int cnt;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  rep(i, n1) L[i] = A[left + i];
  rep(i, n2) R[i] = A[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  int l_idx = 0, r_idx = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if (L[l_idx] <= R[r_idx]) {
      A[k] = L[l_idx];
      l_idx++;
    } else {
      A[k] = R[r_idx];
      r_idx++;
    }
  }

  return;
}

void mergeSort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n, A[MAX_N];
  cin >> n;
  rep(i, n) cin >> A[i];
  cnt = 0;
  mergeSort(A, 0, n);
  rep(i, n) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}

