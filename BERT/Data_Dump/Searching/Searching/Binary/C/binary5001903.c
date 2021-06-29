#include<stdio.h>

int S[100000];

int binarysearch(int q,int n) {
    int high, low,mid;
    high = n - 1;
    low = 0;
    while (high >= low) {
        mid = (high + low) / 2;
        if (S[mid] == q) {
            return 1;
        }
        else if (S[mid] > q) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return 0;
}


int main(void) {
    int i, j, q, n;
    int T[50000];
    int count = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    for (i = 0; i < q; i++) {
        count += binarysearch(T[i], n);
    }

    printf("%d\n",count);

    return 0;
}

