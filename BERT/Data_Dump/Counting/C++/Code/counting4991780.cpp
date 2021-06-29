#include <bits/stdc++.h>
using namespace std;

#define MAX 2000001
#define VMAX 10000


int main(int argc, char const *argv[])
{
  /* 入力 */
  int C[VMAX+1];
  int n;
  cin >> n;
  int A[n+1], B[n+1];

  /* 計数ソート */
  for (int i = 0; i <= VMAX; i++) {
    C[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> A[i+1];
    C[A[i+1]]++;
  }
  // 累積和
  for (int i = 1; i <= VMAX; i++) {
    C[i] += C[i-1];
  }
  // ソート
  for (int i = 1; i <= n; i++) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  /* 出力 */
  for (int i = 1; i <= n; i++) {
    if (i > 1)
    {
      cout << " ";
    }
    cout << B[i];
  }
  cout << endl;

  return 0;
}

