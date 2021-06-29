#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007で割った余り
const long long mod = 1e9 + 7;

using ll  = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rep1r(i, n) for (int i = ((int)(n)); i > 0; --i)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

#define MAX 2000001
#define VMAX 10000

// 教科書のをc++に
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(5);

    int n;
    cin >> n;
    // a入力用 b出力用配列
    int a[n + 1], b[n + 1];
    // カウンター用配列
    int c[VMAX + 1] = {};

    // 	入力はアルゴリズムの都合上1-indexから始める。
    rep1(i, n) {
        cin >> a[i];
        // aの中身をカウントに使う
        c[a[i]]++;
    }

    // カウントを累計していく
    rep1(i, VMAX) { c[i] = c[i] + c[i - 1]; }
    rep1(i, n) {
        // 出力用配列に移動 a=>b
        b[c[a[i]]] = a[i];
        // 出ていった分カウントを減らす
        c[a[i]]--;
    }

    // 出力処理
    rep1(i, n) {
        if (i > 1) cout << " ";
        cout << b[i];
    }
    cout << endl;

    return 0;
}

