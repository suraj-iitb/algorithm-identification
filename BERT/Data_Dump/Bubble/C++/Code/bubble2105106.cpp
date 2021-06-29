#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int MAX = 101;
int n;
int a[MAX];


void solve() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j-1] > a[j]) {
                ans++;
                swap(a[j-1], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}
