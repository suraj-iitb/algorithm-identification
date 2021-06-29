#include <stdio.h>
int main(void){
    int n, A[100], tmp, cnt=0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        if (i != minj) {tmp = A[i]; A[i] = A[minj]; A[minj] = tmp;cnt++;}
    }
    
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    
    printf("%d", cnt);
    
    printf("\n");
    return 0;
}

