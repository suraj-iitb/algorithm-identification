#include <stdio.h>

int main(void)
{
    int N;
    int A[101];
    int v, i, j;

    scanf("%d", &N);
    
    for (i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    for (i = 0; i < N; i++){
        if (i != 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");

    for (i = 1; i <= N - 1; i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        
        for (j = 0; j < N; j++){
            if (j != 0){
                printf(" ");
            }
            printf("%d", A[j]);
        }
        printf("\n");
    }
    return (0);
}

