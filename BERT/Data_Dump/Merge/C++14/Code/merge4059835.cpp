#include <iostream>
using namespace std;
#define INF 1000000001
#define N 500005
int A[N];
int ans = 0;

void merge(int left, int mid, int right) {
  int n1 = mid-left;
  int n2 = right-mid;

  int L[N], R[N];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left+i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid+i];
  }
  L[n1] = INF;
  R[n2] = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    ans++;
  }
}

void mergeSort(int left, int right) {
  if (left + 1 < right) {
    int mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  mergeSort(0, n);
  for (int i = 0; i < n; i++) {
    cout << A[i];
    if (i != n-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  cout << ans << endl;
}


