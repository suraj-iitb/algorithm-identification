#include<stdio.h>

void insertionSort(int* A, int N){

    for(int m=0; m<N; m++){
        if(m!=N-1) printf("%d ", A[m]);
        if(m==N-1) printf("%d\n", A[m]);
        }

    for(int i=1; i<N; i++){
        int v;
        v = A[i];
        int j = i-1;
        while((j>=0)&&(A[j]>v)){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for(int m=0; m<N; m++){
            if(m!=N-1) printf("%d ", A[m]);
            if(m==N-1) printf("%d\n", A[m]);
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    insertionSort(A, n);

    return 0;
}
