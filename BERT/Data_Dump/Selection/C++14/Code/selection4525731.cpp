#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int selectionSort(int A[], int N)
{
  int sw = 0;
  for (int i = 0; i < N; i++)
  {
    int minj = i;
    for (int j = i; j < N; j++)
    {
      if (A[j] < A[minj])
      {
        minj = j;
      }
    }
    if (minj != i)
    {
      swap(A[i], A[minj]);
      // int v = A[i];
      // A[i] = A[minj];
      // A[minj] = v;
      sw++;
    }
  }
  return sw;
}

int main()
{
  int n;
  cin >> n;

  int a[n];
  rep(i, n) cin >> a[i];

  int cnt = selectionSort(a, n);
  rep(i, n) {
    cout << a[i];
    if (i != n - 1)
    {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  cout << cnt << endl;

  return 0;
}

