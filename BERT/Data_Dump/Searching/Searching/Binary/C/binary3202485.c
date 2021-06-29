#include<stdio.h>

int main() {

    int left, right, mid;
    int n, q;
    int S[100000], T[50000];
    int i;
    int count = 0;
    int key;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; ++i) {
        scanf("%d", &T[i]);
    }

    left = 0;
    right = n;

    for (i = 0; i < q; ++i) {
        left = 0;
        right = n;
        key = T[i];
        while (left < right) {
            mid = (left + right) / 2;
            if (S[mid] == key) {
                count++;
                break;
            } else if (key < S[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }
    printf("%d\n",count);

}
