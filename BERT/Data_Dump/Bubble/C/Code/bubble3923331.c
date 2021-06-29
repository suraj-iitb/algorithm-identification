#include <stdio.h>

int main( void ){
    int n, i, j, flag, m, count;
    scanf("%d", &n);
    int A[n];
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    flag = 1;
    i = 0;
	count = 0;
    while(flag == 1){
        flag = 0;
        for(j = n - 1; j >= i + 1; j--){
            if(A[j] < A[j - 1]){
                m = A[j];
                A[j] = A[j - 1];
                A[j - 1] = m;
                flag = 1;
                count++;
            }
        }
        i++;
    }
    for(i = 0; i < n; i++){
        printf("%d", A[i]);
        if(i < n - 1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}

