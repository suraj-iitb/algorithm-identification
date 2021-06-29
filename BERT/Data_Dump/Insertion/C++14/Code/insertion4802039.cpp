#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    // input
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n) {
        scanf("%d", &a[i]);
    }
    // solve
    rep (i, n) {
        // if (i > 0) {
            int x = i;
            while (x-1 >= 0 && a[x-1] > a[x]) {
                swap(a[x], a[x-1]);
                x--;
            }
        // }
        rep(j, n) {
            printf("%d", a[j]);
            if (j != n-1) printf(" ");
        }
        printf("\n");
    }
}
