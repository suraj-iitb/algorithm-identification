#include <stdio.h>

void print(int array[], int n);

int
main(void)
{
        int i, j, k;
        int v;
        int N;
        int A[100];

        scanf("%d", &N);

        for (i = 0; i < N; i++) {
                scanf("%d", &A[i]);
        }

        print(A, N);

        for (j = 1; j < N; j++) {
                v = A[j];
                k =  j - 1;

                while (k >= 0 && A[k] > v) {
                        A[k + 1] = A[k];
                        k--;
                }

                A[k + 1] = v;
                print(A, N);
        }

        return 0;
}

void
print(int array[], int n)
{
        int i;

        printf("%d", array[0]);

        for (i = 1; i < n; i++) {
                printf(" %d", array[i]);
        }

        printf("\n");
}

