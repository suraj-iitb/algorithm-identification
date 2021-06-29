#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdlib>
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
#define VMAX 10000

int main() {
  int N;

  cin >> N;
  vector<int> A(N + 1), B(N + 1), C(VMAX + 1);
  for (int i = 0; i <= VMAX; ++i)
    C[i] = 0;

  for (int i = 0; i < N; ++i) {
    cin >> A[i + 1];
    C[A[i + 1]]++;
  }

  for (int i = 1; i <= VMAX; ++i)
    C[i] += C[i - 1];

  for (int i = 1; i <= N; ++i) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for (int i = 1; i <= N; ++i) {
    if (i > 1)
      cout << " ";
    cout << B[i];
  }
  cout << endl;

  return 0;
}

