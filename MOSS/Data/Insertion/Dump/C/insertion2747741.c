#include <stdio.h>

int main(void)
{
    int n, i, j, tmp;

    scanf("%d", &n);

    int A[n];

    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    for(i = 0; i < n; i++){
        tmp = A[i];
        for(j = i - 1; -1 < j && tmp < A[j]; j--){
            A[j + 1] = A[j];
        }
        A[j + 1] = tmp;

        for(j = 0; j < n; j++){
            printf("%d", A[j]);
            if(j != n - 1) printf(" ");
        }

        printf("\n");
    }

    return 0;
}
