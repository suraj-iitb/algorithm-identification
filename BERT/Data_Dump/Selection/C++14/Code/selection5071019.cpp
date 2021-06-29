#include <iostream>
#include <memory>
using namespace std;

int
main()
{
  int N;
  cin >> skipws >> N;
  auto A = make_unique<int[]>(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int minj, tmp;
  int count = 0;

  for (int i = 0; i < N; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (minj != i) {
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      count++;
    }
  }

  cout << A[0];
  for (int i = 1; i < N; i++) {
    cout << " " << A[i];
  }
  cout << endl;
  cout << count << endl;

  return 0;
}

