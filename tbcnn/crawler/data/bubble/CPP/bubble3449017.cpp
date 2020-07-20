#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;

void bubbleSort(vector<int> A, int N)
{
  int sw = 0;
  REP(i, N)
  {
    for (int j = N - 1; j >= 1; j--)
    {
      if (A[j] < A[j - 1])
      {
        swap(A[j], A[j - 1]);
        sw++;
      }
    }
  }
  REP(i, N)
  {
    cout << A[i];
    if (i < N - 1)
    {
      cout << " ";
    }
  }
  cout << endl << sw << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N)
      cin >> A[i];
  bubbleSort(A, N);
  return 0;
}
