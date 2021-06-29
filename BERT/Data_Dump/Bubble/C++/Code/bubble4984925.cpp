#include <bits/stdc++.h>
using namespace std;

// バブルソート
void bubbleSort (int A[], int N) {
  bool flag = 1; // 順序が逆の隣接要素が存在する
  int cnt = 0;  // 交換回数
  for (size_t i = 0; flag; i++)
  {
    flag = 0;
    for (size_t j = N - 1; j >= i + 1; j--)
    {
      if (A[j - 1] > A[j])
      {
        swap(A[j], A[j - 1]);
        flag = 1;
        cnt++;
      }
    }
  }
  // 出力
  for (size_t i = 0; i < N; i++)
  {
    if (i < N-1)
    {
      cout << A[i] << " ";
    }
    else
    {
      cout << A[i];
    }
  }
  cout << endl;
  cout << cnt << endl;
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

  // バブルソート
  bubbleSort(A, N);

  return 0;
}

