#include <stdio.h>

int bubbleSort(int n, int A[])
{
    int count = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = n-1; j > 0; j--) {
            if (A[j-1] > A[j]) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int i;
    int N;
    int A[100];
    scanf("%d", &N);
    for (i = 0; i < N ;i++) {
        scanf("%d", &A[i]);
    }
    
    int count = bubbleSort(N, A);
    for (i = 0; i < N ;i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
        
    return 0;
}
