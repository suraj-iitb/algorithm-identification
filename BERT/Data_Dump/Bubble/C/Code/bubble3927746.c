#include <stdio.h>

int
bubble_sort(int *A, int N)
{
    int i = 0, j, tmp;
    int flg = 1;
    int cnt = 0;

    while (flg) {
        flg = 0;
        for (j = N -1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flg = 1;
                cnt++;
            }
        }
        i++;
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

    cnt = bubble_sort(A, N);
    print_array(A, N);
    printf("%d\n", cnt);
}
