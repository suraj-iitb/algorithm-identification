#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print(int A[], int N) {

  for (auto i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
}

int main() {
  int N;
  cin >> N;

  int A[N];
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }

  print(A, N);

  for (auto i = 1; i < N; i++) {
    auto key = A[i];
    auto j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;

    print(A, N);
  }

  return 0;
}

