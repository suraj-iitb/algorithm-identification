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
void dump(vector<int> vec){
  rep(i, vec.size()){
    cout << vec[i];
    if(i+1 == vec.size())cout << endl;
    else cout << " ";
  }
}

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
  }
  dump(a);
  FOR(i, 1, n){
    int key = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    dump(a);
  }
	return 0;
}

