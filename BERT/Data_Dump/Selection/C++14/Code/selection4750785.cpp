#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i) {
        auto itr_min = min_element(a.begin() + i, a.end());
        if(a.begin() + i != itr_min) {
            swap(a[i], *itr_min);
            cnt++;
        }
    }

    for(int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        printf(i == n - 1 ? "\n" : " ");
    }
    printf("%d\n", cnt);

    return 0;
}
