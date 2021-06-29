// ! 挿入ソート

// ==========
// 入力例
// ==========
// 6
// 5 2 4 6 1 3

// ==========
// 出力例
// ==========
// 5 2 4 6 1 3
// 2 5 4 6 1 3
// 2 4 5 6 1 3
// 2 4 5 6 1 3
// 1 2 4 5 6 3
// 1 2 3 4 5 6
#include <iostream>
using namespace std;

int main()
{
  int n;

  cin >> n;

  int R[n];

  for (int i = 0; i < n; i++)
  {
    cin >> R[i];
  }
  for (int k = 0; k < n; k++)
  {
    cout << R[k];
    if (k == n - 1)
    {
      cout << endl;
    }
    else
    {
      cout << " ";
    }
  }

  int j, value;

  for (int k = 0; k < n - 1; k++)
  {
    j = k + 1;
    value = R[j];
    while (j > 0 && value < R[j - 1])
    {
      R[j] = R[j - 1];
      j--;
    }
    R[j] = value;
    for (int i = 0; i < n; i++)
    {
      cout << R[i];
      if (i == n - 1)
      {
        cout << endl;
      }
      else
      {
        cout << ' ';
      }
    }
  }

  return 0;
}
