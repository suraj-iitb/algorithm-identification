#include<stdio.h>

void trace(int A[], int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int N){
    int i, v;
    for(i=1;i<N;i++){
        v = A[i];
        int j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

int main(){
    int i, N;
    int num[1000];

    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &num[i]);
    }
    trace(num, N);
    insertionSort(num, N);

    return 0;
}
