#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = (s), i##_len=(n); i < i##_len; ++i)
#define FORS(i, s, n) for(int i = (s), i##_len=(n); i <= i##_len; ++i)
#define VFOR(i, s, n) for(int i = (s); i < (n); ++i)
#define VFORS(i, s, n) for(int i = (s); i <= (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FORS(i, 0, n)
#define VREP(i, n) VFOR(i, 0, n)
#define VREPS(i, n) VFORS(i, 0, n)
#define RFOR(i, s, n) for(int i = (s), i##_len=(n); i >= i##_len; --i)
#define RFORS(i, s, n) for(int i = (s), i##_len=(n); i > i##_len; --i)
#define RREP(i, n) RFOR(i, n, 0)
#define RREPS(i, n) RFORS(i, n, 0)
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<decltype(v[0])>())
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

using ll = long long;
using Pi_i = pair<int, int>;
using VI = vector<int>;
using VD = vector<double>;
using VLL = vector<ll>;
using VS = vector<string>;
using VC = vector<char>;
using VB = vector<bool>;

const int MOD = 1000000007;
const int INF = 1000000000;

template<class T>
bool chmax(T &a, const T &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T>
bool chmin(T &a, const T &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}





void printVector(VI &a){
    int n = SZ(a);
    REP(i, n){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

int selectionSort(VI &a){
    int n = SZ(a), ret = 0, minidx;
    REP(i, n){
        minidx = i;
        FOR(j, i, n){
            if(a[j] < a[minidx])
                minidx = j;
        }
        if(i != minidx){
            ++ret; swap(a[i], a[minidx]);
        }
    }
    return ret;
}

int main(){
    int n; cin >> n;
    VI a(n);
    REP(i, n) cin >> a[i];
    int cnt = selectionSort(a);
    printVector(a);
    cout << cnt << "\n";
    return 0;
}

