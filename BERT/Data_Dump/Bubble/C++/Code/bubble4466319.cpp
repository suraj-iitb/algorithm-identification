#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
void bubbleSort(vector<int> A, int N)
{
  int flag = 1;
  int times = 0;
  while (flag)
  {
    flag = 0;
    int j = 0;
    for (int i = N - 1; i >= j + 1; i--)
    {
      if (A[i] < A[i - 1])
      {
        swap(A[i], A[i - 1]);
        flag = 1;
        times++;
      }
    }
    j++;
  }

  rep(i, N)
  {
    if (i == N - 1)
    {
      cout << A[i];
    }
    else
    {
      cout << A[i] << " ";
    }
  }
  cout << "\n";
  cout << times << endl;
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
  bubbleSort(A, N);
  return 0;
}
