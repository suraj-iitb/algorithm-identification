#include <stdio.h>
#define a 100
#define n 100

int bubbleSort(int A[], int N){
    int flag = 1;
    int j = 0;
    int count = 0;
    int tmp = 0;
    int t = 0;
    
    while(flag == 1){
        flag = 0;
        for(j = N-1; j > 0; j--){
            if(A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
                flag = 1;
            }
        }
    }
    
    for(t = 0; t < N; t++){
        if(t == N-1){
            printf("%d\n", A[t]);
        }else{
            printf("%d ", A[t]);
        }
    }
    printf("%d\n", count);
}

int main(void){
    int A[a] = {};
    int N = 0;
    int i = 0;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    bubbleSort(A, N);
    
    return 0;
}
