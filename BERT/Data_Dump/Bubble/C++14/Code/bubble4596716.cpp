//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    bool flag = 1;
    int cou = 0;
    while(flag) {
        flag = 0;
        for(int j = n-1; j > 0; j--) {
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                flag = 1;
                cou++;
            }
        }
    }

    rep(i, n) {
        cout << a[i] << (i == n-1 ? '\n':' ');
    }
    cout << cou << endl;
}
