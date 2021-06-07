#include <stdio.h>


int biSearch(int s[], int n, int key) {
    int left, mid, right;
    left = 0;
    right = n;
    while (left < right) {
        mid = (left + right) / 2;
        if (s[mid] == key) return 1;
        if (s[mid] < key) left = mid + 1;
        else right = mid;
    }
    return 0;
}


int main() {

    int i, q, cnt, t, s[100000], n;
    cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &s[i]);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &t);
        if (biSearch(s, n, t)) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}


