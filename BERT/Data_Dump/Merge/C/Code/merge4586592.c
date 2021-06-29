#include <stdio.h>
#define LONG_MAX 2147483647

long s[500001];
long L[500001];
long R[500001];

long n, cnt;

void merge(long left, long mid, long right) {
    long i, j, k, n1, n2;

    n1 = mid - left;
    n2 = right - mid;
    for (i = 0; i < n1; i++)
        L[i] = s[left + i];
    for (i = 0; i < n2; i++)
        R[i] = s[mid + i];
    L[n1] = LONG_MAX;
    R[n2] = LONG_MAX;
    i = 0;
    j = 0;
    for (k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            s[k] = L[i];
            i++;
        } else {
            s[k] = R[j];
            j++;
        }
    }
}

void mergeSort(long left, long right) {
    long mid;
    if (left+1 < right) {
        mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    long i;

    scanf("%ld", &n);
    for (i = 0; i < n; i++)
        scanf("%ld", &s[i]);

    cnt = 0;
    mergeSort(0, n);

    for (i = 0; i < n; i++) {
        printf("%ld", s[i]);
        if (i < n-1)
            printf(" ");
        else
            printf("\n");
    }
    printf("%ld\n", cnt);
}

