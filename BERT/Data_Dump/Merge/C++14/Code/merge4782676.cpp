#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif

template <typename A, typename B> bool cmin(A &a, const B &b) {
  return a > b ? (a = b, true) : false;
}
template <typename A, typename B> bool cmax(A &a, const B &b) {
  return a < b ? (a = b, true) : false;
}
const double PI = acos(-1);
const double EPS = 1e-9;
int inf = sizeof(int) == sizeof(long long) ? 2e18 : 1e9 + 10;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define MAX (int)5e5
#define SENTINEL (int)2e9

vector<int> L(MAX/2 + 2), R(MAX/2 + 2);
int cnt;

void merge(vector<int>& a, int n, int left, int mid, int right);
void mergeSort(vector<int>& a, int n, int left, int right);

int main() {
  int N;
  cin >> N;
  vector<int> S(N);
  rep(i, N) cin >> S[i];
  mergeSort(S, N, 0, N);
  for (int i = 0; i < N; ++i) {
    if (i)
      cout << " ";
    cout << S[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}

void merge(vector<int>& a, int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for (int i = 0; i < n1; ++i)
    L[i] = a[left + i];
  for (int i = 0; i < n2; ++i)
    R[i] = a[mid + i];
  L[n1] = R[n2] = SENTINEL;
  for (int i = 0, j = 0, k = left; k < right; ++k) {
    cnt++;
    if (L[i] <= R[j]) {
      a[k] = L[i];
      ++i;
    } else {
      a[k] = R[j];
      ++j;
    }
    // cout<<"a["<<k<<"]: "<<a[k]<<endl;
  }
}

void mergeSort(vector<int>& a, int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid, right);
    merge(a, n, left, mid, right);
  }
}

