#include<stdio.h>

int main(){
    int A[1024], N;
    int i, j, tmp;

    //input data
    scanf("%d", &N);

    for(i=0; i<N; i++) scanf("%d", &A[i]);
    for(j=0; j<N-1; j++){
        printf("%d ", A[j]);
    }
    printf("%d\n", A[j]);


    //insertion sort
    for(i=1; i<N; i++){
        tmp = A[i];
        j = i-1;

        while(j>=0 && A[j]>tmp){
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = tmp;

        for(j=0; j<N-1; j++){
            printf("%d ", A[j]);
        }
        printf("%d\n", A[j]);
    }
        
}

