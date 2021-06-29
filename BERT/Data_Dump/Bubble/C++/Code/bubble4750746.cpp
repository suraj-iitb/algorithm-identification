#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i) {
        for(int j = n - 1; j > i; --j) {
            if(a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                cnt++;
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        printf(i == n - 1 ? "\n" : " ");
    }
    printf("%d\n", cnt);

    return 0;
}
