#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = true;
    int cnt = 0;
    while (flag) {
        flag = false;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                flag = true;
                cnt++;
            }
        }
    }
    cout << a[0];
    for (int i = 1; i < n; i++) cout << " " << a[i];
    cout << endl;
    cout << cnt << endl;
    return 0;
}
