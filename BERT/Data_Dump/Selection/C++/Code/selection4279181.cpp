#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int ans = 0;
    rep(i, n) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) minj = j;
        }
        swap(a[i], a[minj]);
        if (i != minj) ans++;
    }

    rep(i, n) {
        cout << a[i];
        if (i != n-1) cout << ' ';
    }
    cout << endl << ans << endl;
    return 0;
}

