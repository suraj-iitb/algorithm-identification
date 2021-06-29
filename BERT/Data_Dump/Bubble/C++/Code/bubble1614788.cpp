#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <memory>
#include <functional>

using namespace std;

#define ALL(g) (g).begin(), (g).end()
#define REP(i, x, n) for (int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define F(i, j, k) fill(i[0], i[0] + j * j, k)
#define P(p) cout << (p) << endl;
#define EXIST(s, e) ((s).find(e) != (s).end())
#define INF 1 << 25
#define pb push_back

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int main() {
  int n;
  cin >> n;
  vi a;
  rep(i, n) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  int count = 0;
  rep(i, n) {
    for (int j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        count++;
      }
    }
  }
  rep(i, n - 1) cout << a[i] << " ";
  cout << a[n - 1] << endl;
  cout << count << endl;
	return 0;
}
