#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i) {
        a.insert(lower_bound(a.begin(), a.begin() + i, a[i]), a[i]);
        a.erase(a.begin() + i + 1);
        for(int j = 0; j < n; ++j) {
            printf("%d", a[j]);
            printf(j == n - 1 ? "\n" : " ");
        }
    }

    return 0;
}
