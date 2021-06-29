#include <stdio.h>

void bubbleSort(int*, int);

int main(){
    
    int A[255];
    int i, N;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    bubbleSort(A, N);
    
    return 0;
}

void bubbleSort(int A[], int N){
    
    int flag, j, num, count;
    flag = 1;
    count = 0;
    
    while(flag == 1){
        flag = 0;
        for(j = N - 1; j > 0; j--){
            if(A[j] < A[j - 1]){
                num = A[j];
                A[j] = A[j - 1];
                A[j - 1] = num;
                count = count + 1;
                flag = 1;
            }
        }
    }
    
    for(j = 0; j < N - 1; j++){
        printf("%d ", A[j]);
    }
    printf("%d\n", A[j]);
    printf("%d\n", count);
}
