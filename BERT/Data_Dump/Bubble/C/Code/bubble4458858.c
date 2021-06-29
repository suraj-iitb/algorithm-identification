#include <stdio.h>

int bubblesort(int,int *);
int A[102];

int main(void)
{
    int i;
    int N,k;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    k = bubblesort(N, A);

    printf("%d", A[0]);
    for (i = 1; i < N; i++){
        printf(" %d", A[i]);
    }
    printf("\n");
    printf("%d\n", k);


    return (0);
}

int bubblesort(int N, int *A){
    int i;
    int flag;
    int temp;
    int count;

    flag = 1;
    count = 0;
    while (flag){
        flag = 0;
        for (i = N - 1; i > 0; i--){
            if (A[i] < A[i-1]){
                temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                flag = 1;
                count++;
            }
        }
    }
    return count;

}
