#include <bits/stdc++.h>
#define USE_MATH_DEFINES
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int selectionSort(int a[], int n) {
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj])
                minj = j;
        }
        if (i != minj) {
            swap(a[i], a[minj]);
            ans++;
        }
    }

    return ans;
}

int main() {
    int n, ans;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    ans = selectionSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i)
            printf(" %d", a[i]);
        else
            printf("%d", a[i]);
    }
    printf("\n%d\n", ans);
}
