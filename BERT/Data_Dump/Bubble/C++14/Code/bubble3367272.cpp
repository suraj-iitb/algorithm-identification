#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int cnt = 0;

void bubbleSort(vector<int> &a, int n)
{
  bool flag = true;
  while (flag)
  {
    flag = false;
    for (int i = n - 1; i > 0; --i)
    {
      if (a[i] < a[i - 1])
      {
        swap(a[i], a[i - 1]);
        flag = true;
        cnt++;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a)
    cin >> e;
  bubbleSort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << (i + 1 == n ? "\n" : " ");
  cout << cnt << endl;

  return 0;
}

