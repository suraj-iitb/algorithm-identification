#include<stdio.h>
int main(void){
    int A[100];
    int i, j, t, minj, sw = 0, N;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
        t = A[i];
        A[i] = A[minj];
        A[minj] = t;
        sw++;
        }
    }

    printf("%d", A[0]);
    for(i = 1; i < N; i++){
        printf(" %d", A[i]);
    }
    printf("\n");
    printf("%d\n", sw);
    return 0;
}