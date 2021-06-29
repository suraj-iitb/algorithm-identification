#include<stdio.h>

void
print_array(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != (n - 1))
            printf(" ");
    }
    printf("\n");
}

int
main()
{
    int A[100];
    int n, i, j;
    int v;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    print_array(A, n);

    for (i = 1; i < n; i++) {
        v = A[i];
        j = i - 1;
        while ((j >= 0) && (A[j] > v)) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print_array(A, n);
    }

    return 0;
}
