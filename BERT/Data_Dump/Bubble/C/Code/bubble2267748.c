#include <stdio.h>

int main(){
    int A[100];
    int n, m, i, j;
    int count = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    for(i = 0; i < n-1; i++){
        for(j = n-1; j > i; j--){
            if(A[j] < A[j-1]){
                m = A[j];
                A[j] = A[j-1];
                A[j-1] = m;
                count++;
            }
        }
    }
    
    
    for(i = 0; i < n; i++){
        if(i > 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);

  return 0;
}
