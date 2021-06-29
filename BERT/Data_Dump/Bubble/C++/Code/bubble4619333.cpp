#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n;i ++) {
    cin >> A[i];
  }
  int swap {0};

  for (int i = 0; i < n; i++) {
    for (int j = n-1; j > i; j--) {
      if (A[j] < A[j-1]) {
        int tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        swap++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl << swap << endl;
}

