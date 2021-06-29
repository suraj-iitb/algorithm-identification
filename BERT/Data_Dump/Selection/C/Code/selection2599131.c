#include <stdio.h>

int main() {
    
    int n, i, j, minj, temp;
    int A[100];
    int count = 0;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for(i = 0; i < n; i++){
        minj = i;
        for(j = i + 1; j < n; j++){
            if(A[j] < A[minj])
                minj = j;
        }
        if(minj != i){
            temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            count++;
        }
    }
    
    for(i = 0; i < n; i++){
        printf("%d", A[i]);
        if(i != n - 1)
            printf(" ");
    }
    printf("\n%d\n", count);
}
