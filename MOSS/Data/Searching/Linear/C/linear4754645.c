#define N 10005
#define Q 505
#include <stdio.h>
int S[N], T[Q];

int isExist(int x, int n) {
    for (int i = 0; i < n; i++) {
        if (S[i] == x) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int cnt = 0;
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }
    for (int i = 0; i < q; i++) {
        if (isExist(T[i], n)) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
