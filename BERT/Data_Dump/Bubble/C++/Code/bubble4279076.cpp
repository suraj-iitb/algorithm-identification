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
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n-1; j > 0; j--) {
            if (a[j] < a[j-1]) {
                ans++;
                swap(a[j], a[j-1]);
                flag = 1;
            }
        }
    }

    rep(i, n) {
        cout << a[i];
        if (i != n-1) cout << ' ';
    }

    cout << endl << ans << endl;
    return 0;
}

