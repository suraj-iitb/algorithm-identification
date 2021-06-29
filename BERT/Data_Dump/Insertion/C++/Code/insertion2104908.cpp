#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 101;
int n;
int a[MAX];

void print() {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                int t = a[i];
                for (int k = i-1; k >= j; k--) {
                    a[k+1] = a[k];
                }
                a[j] = t;
                break;
            }
        }
        print();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}
