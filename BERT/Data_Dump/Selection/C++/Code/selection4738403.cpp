// ! 選択ソート

// ==========
// 入力例
// ==========
// 6
// 5 6 4 2 1 3

// ==========
// 出力例
// ==========
// 1 2 3 4 5 6
// 4
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

  int swapCount = 0;
  int minValueIndex;
  for (int k = 0; k < n - 1; k++)
  {
    minValueIndex = k;
    for (int j = k; j < n - 1; j++)
    {
      if (R[minValueIndex] > R[j + 1])
      {
        minValueIndex = j + 1;
      }
    }
    if (minValueIndex != k)
    {
      swap(R[k], R[minValueIndex]);
      swapCount++;
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
