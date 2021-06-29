#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int cnt = 0;

void printSequence(int A[], int N)
{
  rep(i, N)
  {
    cout << A[i];
    if (i == N - 1)
    {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

void bubbleSort(int A[], int N)
{
  bool flag = true;
  while (flag)
  {
    flag = false;
    for (int j = N - 1; j > 0; j--)
    {
      if (A[j] < A[j - 1])
      {
        int v = A[j];
        A[j] = A[j - 1];
        A[j - 1] = v;
        flag = true;
        cnt++;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;

  int a[n];
  rep(i, n) cin >> a[i];

  bubbleSort(a, n);
  printSequence(a, n);
  cout << cnt << endl;

  return 0;
}
