#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
void selectionSort(vector<int> A, int N)
{
  int times = 0;
  rep(i, N)
  {
    int minj = i;
    for (int j = minj; j < N; j++)
    {
      if (A[j] < A[minj])
      {
        minj = j;
      }
    }
    if (i != minj) times++;
    swap(A[i], A[minj]);
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
  selectionSort(A, N);
  return 0;
}
