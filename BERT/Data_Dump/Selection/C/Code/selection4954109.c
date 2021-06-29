#include <stdio.h>

int main(void)
{
    int A[100];
    int N;
    int minj;
    int cnt;
    int tmp;
    int i, j;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    cnt = 0;
    for (i = 0; i < N; i++){
        minj = i;
        for (j = i; j < N; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (i != minj){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            cnt++;
        }
    }
    
    for (i = 0; i < N; i++){
        if (i != 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    
    return (0);
}

