// Last Change:                              11/24/2018 02:30:29.
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define INFTY 1000000010
int countNum;
int L[250005];
int R[250005];

void Merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    countNum++;
  }
}

void MergeSort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

int main() {
  int N, A[500000];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  MergeSort(A, 0, N);
  for (int i = 0; i < N; i++) {
    if (i) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << countNum << endl;
}


