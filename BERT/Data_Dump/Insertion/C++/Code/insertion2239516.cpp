#include <iostream>

using namespace std;
static const int MAX=100;

int main () {
  int i, j, p, v, n, A[MAX];

  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];

  // print array
  for (p = 0; p < n; p++) {
    cout << A[p];
    if (p != n-1)
      cout << ' ';
  }
  cout << endl;

  // Insertion Sort
  for (i = 1 ; i < n; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;


    for (p = 0; p < n; p++) {
      cout << A[p];
      if (p != n-1)
        cout << ' ';
    }
    cout << endl;
  }

  return 0;
}
