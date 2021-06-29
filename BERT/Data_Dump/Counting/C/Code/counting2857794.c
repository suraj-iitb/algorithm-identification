#include <stdio.h>

#define MAX 2000000
#define AN 10000

/*
 * Runtime Error
 */

void counting_sort(int B[], int Bn)
{
    int A[AN];
    int C[MAX];
    for (int i = 0; i < AN; i++) {
        A[i] = 0;
    }

    for (int i = 0; i < Bn; i++) {
        A[B[i]]++;
    }

    int q = 0;
    for (int i = 0; i < AN; i++) {
        for (int j = 0; j < A[i]; j++) {
            C[q++] = i;
        }
    }
    for (int i = 0; i < Bn; i++) {
        if (i) printf(" ");
        printf("%d", C[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int B[MAX];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    counting_sort(B, n);

    return 0;
}

