#include<stdio.h>

void bubbleSort(int *A, int N){
    int flag = 1;
    int count = 0;
    while(flag){
        flag = 0;
        for(int j = N-1; j > 0; j--){
            if(A[j] < A[j-1]){
                count++;
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("%d",A[i]);
        if(i < N-1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",count);
}

int main(void){
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    bubbleSort(A, N);
    return 0;
}
