#include <bits/stdc++.h>
#define USE_MATH_DEFINES
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int bubbleSort(int a[], int n) {
    bool flag = true;
    int ans = 0;
    while (flag) {
        flag = false;
        for (int j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = 1;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int n, ans;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    ans = bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i)
            printf(" %d", a[i]);
        else
            printf("%d", a[i]);
    }
    printf("\n%d\n", ans);
}
