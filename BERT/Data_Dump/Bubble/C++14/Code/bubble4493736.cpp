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

void bubble (vector<int> &a, int n, int &cnt) {
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] < a[i - 1]) {
                int v = a[i];
                a[i] = a[i - 1];
                a[i - 1] = v;
                flag = 1;
                cnt++;
            }
        }
    }
    rep (i, n) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> vec (n);
    rep (i, n) cin >> vec[i];
    bubble (vec, n, cnt);
    cout << cnt << "\n";
}

