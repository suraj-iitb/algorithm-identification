#include <iostream>

using namespace std;

const int MAX = 500000;
const int INF = 2147483647;

int L[MAX/2+2];
int R[MAX/2+2];
int c = 0;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; ++i)
    L[i] = A[left + i];
  for (int i = 0; i < n2; ++i)
    R[i] = A[mid + i];
  L[n1] = R[n2] = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; ++k) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    }
    else {
      A[k] = R[j];
      ++j;
    }
    ++c;
  }
}

void mergeSort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  int S[MAX] = {};

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> S[i];

  mergeSort(S, 0, n);

  for (int i = 0; i < n; ++i) {
    cout << S[i];
    if (i == n - 1) cout << "\n";
    else cout << " ";
  }
  cout << c << "\n";
}

