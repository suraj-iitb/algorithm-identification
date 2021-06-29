#include<stdio.h>

void bubbleSort(int A[], int N){
    int flag = 1;
    int tmp;
    int num=0;
    while(flag){
        flag = 0;
        for(int i = 1; i < N; i++){
            if(A[i] < A[i-1]){
                tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                flag = 1;
                num++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(i != 0){
            printf(" "); 
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", num);
}

int main(void){
    int n, a[200];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);


    return 0;   
}
