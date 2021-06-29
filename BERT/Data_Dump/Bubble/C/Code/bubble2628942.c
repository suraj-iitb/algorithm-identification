#include<stdio.h>

void bubble(int A[], int N){
    int flag = 1;
    int temp = 0;
    int counter = 0;
    while(flag){
        flag = 0;
        for(int j = N-1; j > 0; j--){
            if(A[j]<A[j-1]){
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = 1;
                counter++;
            }  
        }
    }
    for(int i = 0;i < N; i++){
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
    bubble(A, N);
    return 0;
}
