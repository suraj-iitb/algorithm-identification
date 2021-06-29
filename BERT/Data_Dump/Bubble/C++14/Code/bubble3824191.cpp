#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define FOR(i,a,b) for (int i=(a),for_##i##_max=(b);i<=(for_##i##_max);++i)
#define RFOR(i,a,b) for (int i=(a),rfor_##i##_min=(b);i>=(rfor_##i##_min);--i)
#define REP(i,n) for (int i=0,rep_##i##_len=(n);i<(rep_##i##_len);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

namespace { // Basics

template<typename T>
void chmin(T &x, T y) {
  x = std::min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
  x = std::max(x, y);
}

template<typename T>
__attribute__((unused))
const auto minimum = static_cast<T const &(*)(T const &, T const &)>(std::min);

template<typename T>
__attribute__((unused))
const auto maximum = static_cast<T const &(*)(T const &, T const &)>(std::max);

template<typename T>
__attribute__((unused))
T constexpr infty = std::numeric_limits<T>::max / 3;
template<>
__attribute__((unused))
auto constexpr infty<int> = 1'100'100'100;
template<>
__attribute__((unused))
auto constexpr infty<long long int> = 100'500'400'300'200'100LL;

using lli = long long int;
using ld = long double;

} // namespace

using namespace std;

void solve(int n, vector<int> &as) {
  int cnt = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = n - 1; j > 0; --j) {
      if (as[j] < as[j - 1]) {
        swap(as[j], as[j-1]);
        ++cnt;
        flag = true;
      }
    }
  }
  bool fst = true;
  for (auto &&a: as) {
    cout << (fst? "":" ") << a;
    fst = false;
  }
  cout << "\n" << cnt << "\n";
}

int main() {
  // cout << fixed << setprecision(10);

  int N; cin >> N;
  vector<int> as;
  REP(i, N) {
    int A;
    cin >> A;
    as.push_back(A);
  }
  solve(N, as);
  return 0;
}

