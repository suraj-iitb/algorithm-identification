#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, flag, n_sort;
  int i, j, k;
  cin >> N;
  flag = 1;
  n_sort = 0;

  vector<int> A;
  for (i = 0; i < N; i++) {
    cin >> k;
    A.push_back(k);
  }

  while (flag) {
    flag = 0;
    for (j = N-1; 0 < j; j--) {
      if (A[j-1] > A[j]) {
        int v = A[j];
        A[j] = A[j-1];
        A[j-1] = v;
        n_sort += 1;
        flag = 1;
      }
    }
  }

  for(j=0;j<N;j++) cout << A[j] << (j==N-1?'\n':' ');
  cout << n_sort << endl;
  return 0;
}

