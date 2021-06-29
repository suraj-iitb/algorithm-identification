#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

void insertionSort(vector<int> &a, int n)
{
  for (int i = 1; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      cout << a[j] << (j + 1 == n ? "\n" : " ");
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a)
    cin >> e;
  insertionSort(a, n);
  for (int j = 0; j < n; ++j)
    cout << a[j] << (j + 1 == n ? "\n" : " ");

  return 0;
}

