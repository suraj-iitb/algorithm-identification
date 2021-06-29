#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int n;
int a[100];
int cnt = 0;

void bubble_sort() {
    bool flag;
    do {
        flag = true;
        rep(i, n) {
            if (i == 0) continue;
            if (a[i-1] > a[i]) {
                swap(a[i-1], a[i]);
                flag = false;
                cnt++;
            }
        }
    } while (!flag);
}

int main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &a[i]);
    }
    bubble_sort();
    rep(i, n) {
        printf("%d", a[i]);
        if (i != n-1) printf(" ");
        else printf("\n%d\n", cnt);
    }
}
