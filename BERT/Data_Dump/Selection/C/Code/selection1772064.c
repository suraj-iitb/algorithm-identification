#include <stdio.h>

void swap(int A[], int i, int j)
{
    int tmp = A[j];
    A[j] = A[i];
    A[i] = tmp;
}

int selectionSort(int n, int A[])
{
    int count = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        int m = i;
        for (j = i+1; j < n; j++) {
            if (A[m] > A[j]) {
                m = j;
            }
        }
        if (m != i) {
            swap(A, i, m);
            count++;
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
    
    int count = selectionSort(N, A);
    for (i = 0; i < N ;i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
        
    return 0;
}
