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

  bool flag = true;
  int tmp;
  int count = 0;
  while (flag) {
    flag = false;
    for (int j = N - 1; j > 0; j--) {
      if (A[j] < A[j - 1]) {
        tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        count++;
        flag = true;
      }
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

