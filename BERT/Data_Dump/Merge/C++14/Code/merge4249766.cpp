#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <valarray>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <limits>
#include <numeric>
#include <utility>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#include <array>
#include <bitset>
#include <complex>
#include <tuple>
#include <random>

using namespace std;
using ll = long long;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int merge(vector<int> &a, int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> l(n1 + 1), r(n2 + 1);
  for (int i = 0; i < n1; ++i)
    l[i] = a[left + i];
  for (int i = 0; i < n2; ++i)
    r[i] = a[mid + i];
  l[n1] = INF, r[n2] = INF;
  int i = 0, j = 0;
  int cnt = 0;
  for (int k = left; k < right; ++k)
  {
    cnt++;
    if (l[i] <= r[j])
    {
      a[k] = l[i];
      i++;
    }
    else
    {
      a[k] = r[j];
      j++;
    }
  }
  return cnt;
}

int mergeSort(vector<int> &a, int left, int right)
{
  int cnt = 0;
  if (left + 1 < right)
  {
    int mid = (left + right) / 2;
    cnt += mergeSort(a, left, mid);
    cnt += mergeSort(a, mid, right);
    cnt += merge(a, left, mid, right);
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<int> s(n);
  for (auto &e : s)
    cin >> e;
  int cnt = mergeSort(s, 0, s.size());
  for (int i = 0; i < n; ++i)
    cout << s[i] << " \n"[i == n - 1];
  cout << cnt << endl;

  return 0;
}

