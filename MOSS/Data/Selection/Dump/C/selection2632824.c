#include<stdio.h>

void selectionSort(int A[],int N){
    int i = 0;
    int j = 0;
    int minj = 0;
    int temp = 0;
    int counter = 0;
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(i!=minj){
            temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            counter++;

        }
    }
    for(i = 0;i < N; i++){
        if(i!=0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", counter);
    return;
}

int main(void){
    int i = 0;
    int N = 0;
    int A[100];
    scanf("%d\n", &N);
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    selectionSort(A, N);
    return 0;
}
