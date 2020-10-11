#include <stdio.h>

int main(void)
{
    int N;
    int A[1001];
    int i,j,k;
    int v;

    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    printf("%d", A[0]);
    for (i = 1; i < N; i++){
        printf(" %d", A[i]);
    }
    printf("\n");

    for (i = 1; i < N; i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
            A[j + 1] = v;
        } 
        printf("%d", A[0]);
        for (k = 1; k < N; k++){
            printf(" %d", A[k]);
        }
        printf("\n");
    }
    return (0);
}
