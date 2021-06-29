// ==========
// 入力例
// ==========
// 5
// 5 3 2 4 1

// ==========
// 出力例
// ==========
// 1 2 3 4 5
// 8
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

  int flag, temp;
  int swapCount = 0;

  flag = 1;
  while (flag)
  {
    flag = 0;
    for (int k = n - 1; k > 0; k--)
    {
      if (R[k] < R[k - 1])
      {
        temp = R[k];
        R[k] = R[k - 1];
        R[k - 1] = temp;
        flag = 1;
        swapCount++;
      }
    }
  }

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
  cout << swapCount << endl;

  return 0;
}
