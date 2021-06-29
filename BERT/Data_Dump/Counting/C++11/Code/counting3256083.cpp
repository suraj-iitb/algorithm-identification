// Last Change:                           11/26/2018 20:12:17.
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

#define NUMMAX 100000

void CountingSort(int A[], int B[], int n) {
  int C[NUMMAX + 5];
  for (int i = 0; i <= NUMMAX; i++) { // = が大事
    C[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    C[A[i]]++;
  }
  for (int i = 1; i <= NUMMAX; i++) {
    C[i] = C[i] + C[i - 1];
  }
  for (int i = n; i >= 0; i--) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }
}

int main() {
  int n, A[2000000], B[2000000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  CountingSort(A, B, n);

  for (int i = 0; i < n; i++) {
    if (i) {
      cout << " ";
    }
    cout << B[i];
  }
  cout << endl;
}

