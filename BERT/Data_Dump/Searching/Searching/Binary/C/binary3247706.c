#include <stdio.h>

int binarysearch(int *A, int key, int n)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (right >= left) {
		mid = (left + right)/2;
        if (A[mid] == key) return 1;
        if ( key < A[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main(void)
{
    int q, i;
    int S[1000000];
    int T;
    int count = 0;
    int n = 15;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        scanf("%d", &T);
        count = count + binarysearch(S, T, n);
    }
    printf("%d\n", count);

    return 0;
}
