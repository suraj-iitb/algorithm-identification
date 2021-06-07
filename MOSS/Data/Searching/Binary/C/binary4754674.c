#define N 100005
#define Q 50005
#include <stdio.h>
int S[N], T[Q];

//这里用二分查找算法，查找给定x是否在S中
int isExist(int x, int n) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (x > S[mid]) {
            left = mid + 1;
        }
        else if (x < S[mid]) {
            right = mid;
        }
        else {
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
