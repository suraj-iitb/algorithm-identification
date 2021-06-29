#include <iostream>
#include <climits>
using namespace std;

int merge(int A[], int left, int mid, int right) {
  int cnt = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  int *L = new int[n1+1];
  int *R = new int[n2+1];
  for (int i = 0; i < n1; i++) L[i] = A[left+i];
  for (int i = 0; i < n2; i++) R[i] = A[mid+i];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    cnt++;
  }
  return cnt;
}

int mergeSort(int A[], int left, int right) {
  int cnt = 0;
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    cnt += mergeSort(A, left, mid);
    cnt += mergeSort(A, mid, right);
    cnt += merge(A, left,  mid, right);
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  int *A = new int[n];
  for (int i = 0; i < n; i++) cin >> A[i];

  int cnt = mergeSort(A, 0, n);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}
