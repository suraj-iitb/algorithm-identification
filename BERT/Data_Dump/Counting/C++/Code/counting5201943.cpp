#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[2000000 + 1];
int B[2000000 + 1];
int C[100000 + 1];

void CountingSort(int A[], int B[], int k) {

  for (int i = 0; i <= k; i++) C[i] = 0;
  for (int j = 1; j <= n; j++) C[A[j]]++;
  for (int i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
  for (int j = n; j >= 1; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(void) {

  int k = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    k = max(k, A[i]);
  }
  CountingSort(A, B, k);

  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    cout << B[i];
  }
  cout << endl;

  return 0;
}
