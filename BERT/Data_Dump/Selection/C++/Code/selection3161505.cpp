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

  int numSwap = 0;
  for (int i = 0; i < num; i++) {
    int argmin = i;
    for (int j = i; j < num; j++) {
      if (A[j] < A[argmin]) {
        argmin = j;
      }
    }
    if (argmin != i) {
      int tmp = A[i];
      A[i] = A[argmin];
      A[argmin] = tmp;
      numSwap++;
    }
  }

  for (int i = 0; i < num - 1; i++) {
    cout << A[i] << " ";
  }
  cout << A[num - 1] << endl;
  cout << numSwap << endl;
}
