#include <stdio.h>

int main() {
    int N, A[100], minj, change, count = 0;
    int i, j;
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    for (i = 0; i < N - 1; i++) {
        minj = i;
        
        for (j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        
        if (A[minj] < A[i]) {
            change = A[i];
            A[i] = A[minj];
            A[minj] = change;
            
            count++;
        }
    }
    
    for (i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        
        printf("%d", A[i]);
    }
    
    putchar('\n');
    
    printf("%d\n", count);
    
    return 0;
}

