#include<iostream>
using namespace std;

#define INFTY 1000000001
int cnt = 0;

void merge(int A[], int left, int mid, int right) {
  int i, j, k;
  int n1, n2;  // 部分列L, Rの要素数決定に利用

  n1 = mid - left;
  n2 = right - mid;

  int L[n1+1], R[n2+1];

  for (i = 0; i < n1; i++) L[i] = A[left + i];
  for (i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;

  // sort
  j = 0;
  k = 0;
  for (i = left; i < right; i++) {
    if (L[j] <= R[k]) {
      A[i] = L[j];
      j++;
      cnt++;
    } else {
      A[i] = R[k];
      k++;
      cnt++;
    }
  }
}

void merge_sort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid;
    mid = (left + right) / 2;
    // devide
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);
    // conquer
    merge(A, left, mid, right);
  }
}

int main() {
  int i, n, S[500000];

  cin >> n;
  for (i = 0; i < n; i++) cin >>  S[i];

  merge_sort(S, 0, n);

  for (i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << S[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}

