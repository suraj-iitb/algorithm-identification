#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

int main()
{
  int R[100], n;
  cin >> n;
  for (size_t i = 0; i < n; i++)
  {
    cin >> R[i];
    cout << R[i];
    if (i != n - 1)
      cout << " ";
  }

  cout << endl;

  for (size_t i = 1; i < n; i++)
  {
    int v = R[i];  // 2
    int j = i - 1; // 0
    while (j >= 0 && R[j] > v)
    {
      R[j + 1] = R[j];
      R[j] = v;
      j--;
    }
    for (size_t i = 0; i < n; i++)
    {
      cout << R[i];
      if (i != n - 1)
        cout << " ";
      else
        cout << endl;
    }
  }

  return 0;
}

