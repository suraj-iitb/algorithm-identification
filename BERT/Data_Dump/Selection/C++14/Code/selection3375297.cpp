#include "bits/stdc++.h"
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, k, n) for(auto i = k; i != n; i++)
#define rrep(i, n) RREP(i, n, 0)
#define RREP(i, n, k) for(auto i = n; i != k; i--)

#define debug(x) cerr << #x << " " << x << endl
#define print(x) cout << x;
#define println(x) cout << x << endl;
#define spc << " " <<

#define mp make_pair
#define mt make_tuple
#define pf push_front
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define eb emplace_back
#define np next_permutation

using ll = long long;
using Pii = pair<int, int>;
using Tiii = tuple<int, int, int>;
template<class T>using V = vector<T>;
template<class T>using VV = vector<vector<T>>;
using Vi = vector<int>;
using VVi = vector<vector<int>>;

int main() {
   int N; cin >> N;
   Vi A = Vi(N); rep(i, N) cin >> A[i];

   int ans = 0;
   rep(i, N-1) {
      int min_i = i;
      REP(j, i, N) {
         if (A[min_i] > A[j]) min_i = j;
      }
      swap(A[min_i], A[i]);
      if (min_i != i) ans++;
   }
   cout << A[0]; REP(i, 1, N) cout << " " << A[i]; cout << endl;
   cout << ans << endl;
   return 0;
}

