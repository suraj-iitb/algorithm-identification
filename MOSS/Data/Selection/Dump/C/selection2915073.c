#include <stdio.h>

int selection_sort(int *a, int n) {
    int i, j, tmp, count=0, mini;

    for (i=0;i<n;i++) {
        mini=i;
        for (j=i;j<n;j++) {
            if (a[j]<a[mini]) {
                mini=j;
            }
        }
        tmp=a[i];
        a[i]=a[mini];
        a[mini]=tmp;
        if (i!=mini) count++;
    }
    return count;
}

int main(void) {
    int i, n, count, arr[100];

    scanf("%d", &n);
    for (i=0;i<n;i++) scanf("%d", &arr[i]);
    count=selection_sort(arr, n);
    for (i=0;i<n;i++) {
        printf("%d", arr[i]);
        if (i<n-1) printf(" ");
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}

