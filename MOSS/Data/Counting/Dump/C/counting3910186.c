#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

int
main(void)
{
        unsigned short *A, *B;

        int C[VMAX + 1];
        int A_len;
        int i, j;

        scanf("%d", &A_len);

        A = malloc(sizeof(short) * A_len + 1);
        B = malloc(sizeof(short) * A_len + 1);

        for (i = 0; i <= VMAX; i++)
                C[i] = 0;

        for (i = 0; i < A_len; i++) {
                scanf("%hu", &A[i + 1]);
                C[A[i + 1]]++;
        }

        for (i = 1; i <= VMAX; i++)
                C[i] = C[i] + C[i - 1];

        for (j = 1; j <= A_len; j++) {
                B[C[A[j]]] = A[j];
                C[A[j]]--;
        }

        for (i = 1; i <= A_len; i++) {
                if (i > 1)
                        printf(" ");
                printf("%d", B[i]);
        }
        printf("\n");

        return 0;
}

