// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)cin >> a[i];
  int res = 0;
  bool flag = true;
  while(flag){
    flag = false;
    for(int j = n - 1; j > 0; j--){
      if(a[j] < a[j-1]){
        flag = true;
        res++;
        swap(a[j], a[j-1]);
      }
    }
  }
  rep(i, n){
    cout << a[i];
    if(i + 1 == n)cout << endl;
    else cout << " ";
  }
  cout << res << endl;
	return 0;
}

