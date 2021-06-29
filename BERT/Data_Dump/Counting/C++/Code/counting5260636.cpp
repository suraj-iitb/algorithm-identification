#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

int n;

void countingSort(int* a, int* b, int k) {
    int c[k + 1];
    for (int i = 0; i <= k; i += 1) c[i] = 0;
    for (int i = 0; i <  n; i += 1) c[a[i]] += 1;
    for (int i = 1; i <= k; i += 1) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i -= 1) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] -= 1;
    }
}

int main() {
    scanf("%d", &n);
    int ans[n];
    int a[n];
    rep(i, n) scanf("%d", &a[i]);
    int max = 0;
    rep(i, n) max = max > a[i] ? max : a[i];
    countingSort(a, ans, max);
    rep(i, n) {
        printf("%d", ans[i]);
        if (i < n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
