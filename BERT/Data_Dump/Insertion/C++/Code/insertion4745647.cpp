#include<stdio.h>

void insertion_sort(int *A, int N){
    int i;
    for (i=1;i<N;i++){
        int v=A[i];
        int j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        int k;
        for(k=0;k<N-1;k++){
        printf("%d ",A[k]);
        }
        printf("%d\n",A[N-1]);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int A[N];
    int i;
    for (i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    for (i=0;i<N-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[N-1]);
    insertion_sort(A,N);
    return 0;
}