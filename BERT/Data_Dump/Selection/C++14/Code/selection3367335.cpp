#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int cnt = 0;

void selectionSort(vector<int> &a, int n)
{
  for (int i = 0; i < n; ++i)
  {
    int minj = i;
    for (int j = i; j < n; ++j)
    {
      if (a[j] < a[minj])
        minj = j;
    }
    if (i != minj)
      cnt++;
    swap(a[i], a[minj]);
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a)
    cin >> e;
  selectionSort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << (i + 1 == n ? "\n" : " ");
  cout << cnt << endl;

  return 0;
}

