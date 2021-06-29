#include <stdio.h>

int main(void)
{
    int A[100];
    int N;
    int cnt;
    int tmp;
    int flag, i, j;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    cnt = 0;
    flag = 1;
    while (flag == 1){
        flag = 0;
        for (j = N - 1; j >= 1; j--){
            if (A[j] < A[j - 1]){
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
                cnt++;
            }
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

