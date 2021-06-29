#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
void insertionSort(vector<int> A, int N) // N個の要素を含む0-オリジンの配列A
{
  for (int i = 1; i < N + 1; i++)
  {
    rep(k, N)
    {
      if (k == N - 1)
      {
        cout << A[k];
      }
      else
      {
        cout << A[k] << " ";
      }
    }
    cout << "\n";

    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v)
    {
      A[j + 1] = A[j];
      j--;
      A[j + 1] = v;
    }
  }
}
int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }
  insertionSort(A, N);
  return 0;
}
