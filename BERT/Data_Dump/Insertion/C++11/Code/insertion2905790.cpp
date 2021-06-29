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

  // input
  int n;
  cin >> n;

  std::vector<int> A;
  for (size_t i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  // processing
  for (size_t i = 0; i < A.size(); i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    int a_last = A.back();
    A.pop_back();

    for (int x : A) {
      cout << x << " ";
    }

    cout << a_last << endl;

    A.push_back(a_last);
  }

  // output
  // for (int x : A) {
  //   cout << x << " ";
  // }
  //
  // cout << endl;

  return 0;
}

