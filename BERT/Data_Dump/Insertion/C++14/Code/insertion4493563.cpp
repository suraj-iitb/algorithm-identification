#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void insertion (vector<int> &a, int n) {
    for (int i = 1; i < n; i++) {
        int v = a[i], j = i - 1;
        while (a[j] > v && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        rep (k, n) {
            if (k) cout << " ";
            cout << a[k];
        }
        cout << "\n";
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec (n);
    rep (i, n) cin >> vec[i];
    rep (k, n) {
        if (k) cout << " ";
        cout << vec[k];
    }
    cout << "\n";
    insertion (vec, n);
}
