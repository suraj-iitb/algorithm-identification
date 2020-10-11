#include <stdio.h>

int bubble_sort(int *a, int m) {
    int i, j, tmp, n=0;

    for (i=0;i<m;i++) {
        for (j=m-1; j>i; j--) {
            if (a[j]<a[j-1]) {
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                n++;
            }
        }
    }

    return n;
}

int main(void) {
    int i, n, count, arr[100];

    scanf("%d", &n);
    for (i=0; i<n; i++) scanf("%d", &arr[i]);
    count=bubble_sort(arr, n);
    for (i=0; i<n; i++) {
        printf("%d", arr[i]);
        if (i<n-1) printf(" ");
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}

