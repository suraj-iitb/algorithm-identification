#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
#include <cmath>
#include <iomanip>
#include <ctype.h>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi >;
using vl = vector<ll>;
using vvl = vector<vl >;
using pairi = pair<int, int>;
using pairl = pair<ll, ll>;

static const ll MAX = 200000;
static const ll waz = 76543217;

#define TR ","
#define TS " "
#define rep(i,N) for(ll i=0;i<(ll)N;++i)
#define rpt(i,a,b) for(ll i=a;i<(ll)b;++i)
#define all(v) v.begin(), v.end()
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

void printVector(const vector<ll>& vec) {
    for (ll value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

ll selectionSort(ll A[], ll N) {
    ll i, t, j, jj = 0, minj;
    rep(i, N - 1) {
        minj = i;
        rpt(j, i, N) {
            if (A[j] < A[minj]) minj = j;
        }
        t = A[i]; A[i] = A[minj]; A[minj] = t;
        if (i != minj) ++jj;
    }
    return jj;
}

int main()
{
    IO;

    ll N, jj; cin >> N;
    ll A[100];
    rep(i, N) cin >> A[i];

    jj = selectionSort(A, N);

    rep(i, N) {
        if (i) {
            cout << " " << A[i];
        }
        else {
            cout << A[i];
        }
    }
    cout << endl;
    cout << jj << endl;
}
