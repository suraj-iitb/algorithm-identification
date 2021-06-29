#include <bits/stdc++.h>
using namespace std;

// 選択ソート
int selectionSort (int A[], int N) {
  int cnt = 0;
  for (size_t i = 0; i < N; i++)
  {
    int min_j = i;
    for (size_t j = i; j < N; j++)
    {
      if (A[j] < A[min_j])
      {
        min_j = j;
      }
    }
    swap(A[i], A[min_j]);
    if (i != min_j)
    {
      cnt++;
    }
  }
  return cnt;
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N;
  cin >> N;
  int A[N];
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  // 選択ソート
  int ans = selectionSort(A, N);

  // 出力
  for (size_t i = 0; i < N; i++)
  {
    if (i < N-1)
    {
      cout << A[i] << " ";
    }
    else
    {
      cout << A[i] << endl;
    }
  }
  cout << ans << endl;

  return 0;
}

