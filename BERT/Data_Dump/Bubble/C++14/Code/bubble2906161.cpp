#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
  int N;
  cin >> N;

  std::vector<int> A;
  for (size_t i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  int swap_count = 0;
  for (size_t i = 0; i < N; i++) {
    int j = N - 1;
    while (j > i) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        swap_count++;
      }
      j--;
    }
  }

  int a_last = A.back();
  A.pop_back();
  for (int a : A) {
    std::cout << a << ' ';
  }

  std::cout << a_last << '\n';

  std::cout << swap_count << '\n';

  return 0;
}

