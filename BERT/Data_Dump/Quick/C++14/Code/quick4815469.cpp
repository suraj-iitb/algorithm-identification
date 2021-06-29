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

#define MAX (int)1e5
#define SENTINEL (int)2e9

struct Card {
  char suit;
  int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int n, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for (i = 0; i < n1; ++i)
    L[i] = A[left + i];
  for (i = 0; i < n2; ++i)
    R[i] = A[mid + i];
  L[n1].value = R[n2].value = SENTINEL;
  i = j = 0;
  for (k = left; k < right; ++k) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(struct Card A[], int n, int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int partition(struct Card A[], int n, int p, int r) {
  int i, j;
  struct Card t, x;
  x = A[r];
  i = p - 1;
  for (j = p; j < r; ++j) {
    if (A[j].value <= x.value) {
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i + 1];
  A[i + 1] = A[r];
  A[r] = t;
  return i + 1;
}

void quickSort(struct Card A[], int n, int p, int r) {
  int q;
  if (p < r) {
    q = partition(A, n, p, r);
    quickSort(A, n, p, q - 1);
    quickSort(A, n, q + 1, r);
  }
}

int main() {
  int N, V;
  bool stable = true;
  cin >> N;
  struct Card A[MAX], B[MAX];
  char S;
  rep(i, N) {
    cin >> S >> V;
    A[i].suit = B[i].suit = S;
    A[i].value = B[i].value = V;
  }

  mergeSort(A, N, 0, N);
  quickSort(B, N, 0, N - 1);

  for (int i = 0; i < N; ++i) {
    if (A[i].suit != B[i].suit)
      stable = false;
  }

  if (stable)
    cout << "Stable" << endl;
  else
    cout << "Not stable" << endl;

  for (int i = 0; i < N; ++i) {
    cout << B[i].suit << " " << B[i].value << endl;
  }

  return 0;
}

