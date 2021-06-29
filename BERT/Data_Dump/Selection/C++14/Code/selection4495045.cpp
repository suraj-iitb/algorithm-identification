#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void selection (int n, vector<int> &a) {
    int cnt = 0;
    rep (i, 0, n) {
        int minj = i;
        rep (j, i, n) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            int v = a[i];
            a[i] = a[minj];
            a[minj] = v;
            cnt++;
        }
        // rep (i, 0, n) cout << a[i] << " ";
        // cout << "\n";
    }
    rep (i, 0, n) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n" << cnt << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> a (n);
    rep (i, 0, n) cin >> a[i];
    selection (n, a);
}
