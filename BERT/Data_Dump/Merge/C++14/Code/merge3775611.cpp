#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

typedef long long ll;

#define INF 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

// merge sort

int cnt = 0;

void merge(vector<int>& a, int left, int mid, int right) {
  // cout << left << " " << mid << " " << right << endl;
  constexpr int inf = numeric_limits<int>::max();
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1+1), R(n2+1);
  for (int i = 0; i < n1; ++i) {
    L.at(i) = a.at(left+i);
  }
  for (int i = 0; i < n2; ++i) {
    R.at(i) = a.at(mid+i);
  }
  L.at(n1) = inf;
  R.at(n2) = inf;
  int i = 0, j = 0;
  for (int k = left; k < right; ++k) {
      cnt += 1;
    if (L[i] <= R[j]) {
      a[k] = L[i++];
    } else {
      a[k] = R[j++];
    }
  }
}

void mergeSort(vector<int>& a, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  rep(i, n) cin >> a[i];

  mergeSort(a, 0, n);
  
  for (int i = 0; i < n; ++i) {
    if (i == n-1) cout << a[i];
    else cout << a[i] << " ";
  }
  
  cout << "\n" << cnt << endl;
}

