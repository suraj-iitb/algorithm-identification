#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    bool flag = true;
    int cnt = 0;
    while (flag) {
        flag = false;
        for (int j=n-1; j>=1; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                cnt++;
                flag = true;
            }
        }
    }

    rep(i, n) cout << a[i] << ((i<n-1) ? " " : "\n");
    cout << cnt << endl;
}
