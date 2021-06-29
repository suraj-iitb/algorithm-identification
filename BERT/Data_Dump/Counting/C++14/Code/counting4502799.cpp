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

int a[2000005], b[2000005];

void CountingSort (int n, int k) {
    int c[k + 1] = {};
    rep (i, 0, n) c[a[i]]++;
    // rep (i, 0, k + 1) cout << c[i] << " ";
    // cout << "\n";
    rep (i, 1, k + 1) c[i] += c[i - 1];
    // rep (i, 0, k + 1) cout << c[i] << " ";
    // cout << "\n";
    rep (i, 0, n) { b[--c[a[i]]] = a[i]; }
    rep (i, 0, n) {
        if (i) cout << " ";
        cout << b[i];
    }
    cout << "\n";
}

int main() {
    int n, k = 0;
    cin >> n;
    rep (i, 0, n) {
        cin >> a[i];
        k = max (k, a[i]);
    }
    CountingSort (n, k);
}
