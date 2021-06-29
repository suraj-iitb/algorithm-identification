#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, tmp;
  vector<int> A;
  cin >> N;
  for (size_t i = 0; i < N; i++)
  {
    cin >> tmp;
    A.push_back(tmp);
  }

  // 出力
  for (size_t i = 0; i < N - 1; i++)
  {
    cout << A[i] << " ";
  }
  cout << A[N - 1] << endl;

  // 挿入ソート
  for (size_t i = 1; i < N; i++)
  {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    // 出力
    for (size_t i = 0; i < N-1; i++)
    {
     cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
  }

  return 0;
}

