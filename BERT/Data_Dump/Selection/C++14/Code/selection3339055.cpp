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
  rep(i, n){
    int minj = i;
    FOR(j, i, n){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    swap(a[i], a[minj]);
    if(i != minj)res++;
  }
  rep(i, n){
    cout << a[i];
    if(i + 1 == n)cout << endl;
    else cout << " ";
  }
  cout << res << endl;
	return 0;
}

