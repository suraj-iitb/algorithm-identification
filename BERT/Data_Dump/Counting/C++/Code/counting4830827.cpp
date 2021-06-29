#include <iostream>

using namespace std;

void CountingSort(int *A, int *B, int k, int n) {
  int C[k+1];
  for(int i = 0; i < k+1; i++) C[i] = 0;

  /* C[i]にiの出現数を記録する */
  for(int j = 0; j < n; j++) C[A[j]]++;

  /* C[i]にi以下の数の出現数を記録 */
  for(int i = 1; i < k+1; i++) C[i] = C[i] + C[i-1];

  for(int j = n-1; 0 <= j; j--) {
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}

int main() {
  int n;
  cin >> n;
  int A[n], B[n];
  int k = 0;
  for(int i = 0; i < n; i++) {
    B[i] = 0;
    cin >> A[i];
    k = max(k, A[i]);
  }

  CountingSort(A, B, k, n);

  for(int i = 0; i < n; i++) {
    cout << B[i];
    if(i != n-1) cout << " ";
    else cout << endl;
  }

  return 0;
}

