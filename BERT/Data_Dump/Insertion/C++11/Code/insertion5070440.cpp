#include <iostream>
#include <memory>
using namespace std;

void
print_array(unique_ptr<int[]>& ary, int len)
{
  cout << ary[0];
  for (int i = 1; i < len; i++) {
    cout << " " << ary[i];
  }
  cout << endl;
}

int
main()
{
  int N;
  cin >> skipws >> N;
  auto A = unique_ptr<int[]>(new int[N]);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  print_array(A, N);

  for (int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    print_array(A, N);
  }

  return 0;
}

