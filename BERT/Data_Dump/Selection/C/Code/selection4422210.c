#include <stdio.h>
#include <stdlib.h>

void swap (int *, int *);
void print_a (int *, int);

int main (void) {
    int n, count=0;
    int *a;

    scanf ("%d", &n);
    a = (int *) malloc (sizeof(int) * n);
    for (int i=0; i<n; i++) scanf ("%d", a+i);

    for (int i=0; i<n; i++) {
        int mini=i;
        for (int j=i; j<n; j++) {
            if (a[j]<a[mini]) mini=j;
        }
        if (i!=mini) {
            swap (a+i, a+mini);
            count++;
        }
    }

    print_a (a, n);
    printf ("%d\n", count);

    free(a);
    return 0;
}

void swap (int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void print_a (int *a, int n) {
    for (int j=0; j<n; j++) {
        if (j==n-1) printf ("%d\n", a[j]);
        else printf ("%d ", a[j]);
    }
}
