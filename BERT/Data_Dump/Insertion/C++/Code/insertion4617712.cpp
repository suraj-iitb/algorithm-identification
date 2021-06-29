#include <iostream>
#include <algorithm>
using namespace std;

void display_array(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << "\n";
}

int main() {
  int n;
  cin >> n;
   
  int A[100];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  display_array(A, n);
  for (int i = 1; i < n; i++) {
    int key = A[i];
    for (int j = i; j >= 0; j--) {
      if (j == 0 || key > A[j-1]) {
        A[j] = key;
        break;
      }
      A[j] = A[j-1];
    }
    display_array(A, n);
  }
  return 0;
}

