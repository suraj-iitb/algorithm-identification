#include <stdio.h>

#define MAX  2000000
#define VMAX 10000

static int A[MAX];
static int B[MAX];

int main()
{
    int n;
    int C[VMAX + 1];

    scanf("%d", &n);
    for (int i = 0; i <= VMAX; i++) {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        C[A[i]]++;
    }

    for (int i = 1; i <= VMAX; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = 0; i < n; i++) {
        C[A[i]]--;
        B[C[A[i]]] = A[i];
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
