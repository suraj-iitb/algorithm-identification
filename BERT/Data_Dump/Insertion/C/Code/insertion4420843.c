#include <stdio.h>
#include <stdlib.h>

void print_a (int *, int);

int main (void) {
    int n;
    int *a;

    scanf ("%d", &n);

    a = (int *) malloc (sizeof(int) * n);
    for (int i=0; i<n; i++) scanf ("%d", a+i);

    for (int i=0; i<n; i++) {
        int key = a[i];
        int j = i-1;
        for (; key<a[j] && j>=0; j--) a[j+1] = a[j];
        a[j+1] = key;
        print_a (a, n);
    }

    free (a);
    return 0;
}

void print_a (int *a, int n) {
    for (int j=0; j<n; j++) {
            if (j==n-1) printf ("%d\n", a[j]);
            else printf ("%d ", a[j]);
        }
}
