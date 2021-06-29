#include <stdio.h>

void BubbleSort(int *, int);
int count=0;

int main()
{
    int i, N;
    int A[100];
    
    scanf("%d", &N);
    for(i=0; i < N; i++){
        scanf("%d", &A[i]);
    }
    for(i=0; i < N; i++){
        BubbleSort(A, N);
    }
    
    for(i=0; i < N; i++){
        if(i != 0)printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
    return 0;
}

void BubbleSort(int A[], int N)
{
    int i, flag=1, str;
    while(flag){
        flag = 0;
        for(i=N-1; i > 0; i--){
            if(A[i] < A[i-1]){
                str = A[i-1];
                A[i-1] = A[i];
                A[i] = str;
                count++;
            }
        }
    }
}
