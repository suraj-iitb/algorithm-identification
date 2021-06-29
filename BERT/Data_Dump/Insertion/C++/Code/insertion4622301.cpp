#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n,0);
    rep(i, n) {
        scanf("%d", &a[i]);
    }

    rep (i, n) {
        if (i != 0) {
            int x = i;
            while (a[x-1] > a[x] && x >= 1) {
                swap(a[x], a[x-1]);
                x--;
            }
        }
        rep(i, n) {
            printf("%d", a[i]);
            if (i != n - 1) printf(" ");
        }
        printf("\n");
    }
}
