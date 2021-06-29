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

    int count = 0;
    for (int i = 0; i < n; i++) {
        int min_j = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min_j]) min_j = j;
        }
        if (i != min_j) {
            swap(a[i], a[min_j]);
            count++;
        }
    }

    rep(i, n) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n%d\n", count);
}
