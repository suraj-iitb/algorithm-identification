#include <bits/stdc++.h>
using namespace std;

int L[500010];
int R[500010];
int cnt;
int INF = 1000000007;

void merge (int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;
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

void mergeSort (int A[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int main() {
  
  int A[500010];
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  mergeSort(A, n, 0, n);

  for (int i = 0; i < n; i++) {
    cout << A[i];
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;

  cout << cnt << endl;

  return 0;

}
