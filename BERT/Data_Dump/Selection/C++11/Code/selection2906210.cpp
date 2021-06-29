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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  std::vector<int> A;
  rep(i, n) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  int count = 0;
  rep(i, n) {
    int minj = i;
    int j = i;
    while (j < n) {
      if (A[j] < A[minj]) {
        minj = j;
      }
      j++;
    }
    if (i != minj) {
      swap(A[i], A[minj]);
      count++;
    }
  }

  rep(i, A.size() - 1) { std::cout << A[i] << ' '; }
  std::cout << A.back() << '\n';

  std::cout << count << '\n';
  return 0;
}

