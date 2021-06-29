// C++11
#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int main() {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int count = 0;

  for (int i = 0; i < N; i++) {
    int mini = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[mini]) {
        mini = j;
      }
    }
    if (i != mini) {
      swap(A[i], A[mini]);
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

  return 0;
}

