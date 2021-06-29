#include <stdio.h>

int main() {
    int N, A[100], flag, change, count = 0;
    int i, j;
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    flag = 1;
    
    while (flag) {
        flag = 0;
        
        for (j = N - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                change = A[j - 1];
                A[j - 1] = A [j];
                A[j] = change;
                
                count++;
                
                flag = 1;
            }
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
