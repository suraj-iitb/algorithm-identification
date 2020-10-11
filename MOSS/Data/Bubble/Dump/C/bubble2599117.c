#include <stdio.h>

int main() {
    
    int n, i, j, temp;
    int A[100];
    int flag = 1;
    int count = 0;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    while(flag){
        flag = 0;
        for(j = n - 1; j > 0; --j){
            if(A[j] < A[j - 1]){
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                count++;
                flag = 1;
            }
        }
    }
    
    for(i = 0; i < n; i++){
        printf("%d", A[i]);
        if(i != n - 1)
            printf(" ");
    }
    printf("\n%d\n", count);
}
