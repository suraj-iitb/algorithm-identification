#include <stdio.h>

void printa(int A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i < N-1) printf(" ");
    }
    printf("\n");
}

int main()
{
    int N;
    int A[100];
    int i, j, v;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    printa(A, N);
    
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (A[j] > v && j >= 0) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printa(A, N);
    }
    
    return 0;
}
