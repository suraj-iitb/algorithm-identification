#include <iostream>
#include <memory>
// #include <iomanip>
using namespace std;

void
countingSort(int A[], int B[], int n, int k)
{
  auto C = make_unique<int[]>(k + 1);

  for (int j = 0; j < n; j++) {
    C[A[j]]++;
  }

  for (int i = 1; i <= k; i++) {
    C[i] += C[i - 1];
  }

  for (int j = n - 1; j >= 0; j--) {
    B[C[A[j]] - 1] = A[j];
    C[A[j]]--;
  }
}

int
main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cout << fixed << setprecision(5);

  const int k = 10000;
  int n;
  cin >> n;
  auto A = make_unique<int[]>(n);
  auto B = make_unique<int[]>(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  countingSort(A.get(), B.get(), n, k);

  if (n > 0) {
    cout << B[0];
  }
  for (int i = 1; i < n; i++) {
    cout << " " << B[i];
  }
  cout << "\n";

  return 0;
}

