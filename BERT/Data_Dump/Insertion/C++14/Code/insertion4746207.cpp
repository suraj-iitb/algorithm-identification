#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    for(int i = 1; i < n; i++) {
        rep(j, n-1) cout << a[j] << ' ';
        cout << a[n-1] << endl;
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    rep(j, n-1) cout << a[j] << ' ';
    cout << a[n-1] << endl;
}
