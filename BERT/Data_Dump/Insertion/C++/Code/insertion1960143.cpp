#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int i, n, j, k, v;
  cin >> n;
  int A[n];
  for (i = 0; i < n; i++) cin >> A[i];
  for (i = 0; i < n - 1; i++) cout << A[i] << " ";
  cout << A[n - 1] << endl;
  for (i = 1; i < n; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for (k = 0; k < n - 1; k++) cout << A[k] << " ";
    cout << A[n - 1] << endl;
  }
  return 0;
}
