#include <iostream>

using namespace std;

static const int MAX = 100;

int main () {
  int N, A[MAX];

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int count = 0;

  for (int i = 0; i < N; i++) {
    int minj = i;
    int origin = A[i];
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }

    if (i != minj) {
      A[i] = A[minj];
      A[minj] = origin;
      count++;
    }

  }

  for (int i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }

  cout << endl;
  cout << count << endl;

}
