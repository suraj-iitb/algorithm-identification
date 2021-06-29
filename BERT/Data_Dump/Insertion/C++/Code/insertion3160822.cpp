#include <iostream>
using namespace std;

int main() {
  int num;
  cin >> num;

  int *A;
  A = new int[num];
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < num - 1; i++) {
    cout << A[i] << " ";
  }
  cout << A[num - 1] << endl;

  for (int i = 1; i < num; i++) {
    int key = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;

    for (int i = 0; i < num - 1; i++) {
      cout << A[i] << " ";
    }
    cout << A[num - 1] << endl;
  }

  return 0;
}
