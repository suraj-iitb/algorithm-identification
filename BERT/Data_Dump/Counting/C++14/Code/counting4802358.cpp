#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)

int n;
int MAX = 10000;
int a[2000000];
int c[10001];

void counting_sort() {
    rep(i, n) {
        c[a[i]]++;
    }
    rep(i, MAX) {
        c[i+1] += c[i];
    }
    vector<int> b(n);
    repr(i, n) {
        c[a[i]]--;
        b[c[a[i]]] = a[i];
    }
    rep(i, n) {
        a[i] = b[i];
    }
}

int main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &a[i]);
    }
    counting_sort();
    rep(i, n) {
        printf("%d", a[i]);
        if (i != n-1) printf(" ");
        else printf("\n");
    }
}
