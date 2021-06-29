#include<stdio.h>

#define M 100

void insertionSort(int *, int);

int main(){
    int N, A[M], i, j, v;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    insertionSort(A, N);
    
    return 0;
}

void insertionSort(int *A, int N){
    int i, j, k, v;

    for(k=0;k<N;k++){
        if(k < N-1){
            printf("%d ",A[k]);
        }
        else{
            printf("%d\n",A[k]);
        }
    }
    for(i=1;i<N;i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(k=0;k<N;k++){
            if(k < N-1){
                printf("%d ",A[k]);
            }
            else{
                printf("%d\n",A[k]);
            }
        }
    }
}
