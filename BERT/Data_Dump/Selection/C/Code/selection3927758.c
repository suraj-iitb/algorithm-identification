#include <stdio.h>

int
selection_sort(int *A, int N)
{
    int i, j, minj, tmp;
    int cnt = 0;

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i + 1; j < N; j++) {
            if (A[j] < A[minj])
                minj = j;
        }
        if (A[i] != A[minj]) {
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            cnt++;
        }
    }
    return cnt;
}

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
    int N, i, cnt;
    int A[100];

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    cnt = selection_sort(A, N);
    print_array(A, N);
    printf("%d\n", cnt);
}
