#include <stdio.h>

/* output function */
void trace(int A[], int N){
    int i;
    for( i = 0; i < N; i++ ){
        if( i > 0) printf(" "); // single space to separate elments
        printf("%d", A[i]);
    }
    printf("\n");
}

/* Selction Sort (0-origin) */
void SelectionSort(int A[], int N){
    int i, j, v, minj;
    int c = 0; // number of swap operations

    for( i = 0; i < N; i++){
        
        minj = i;
        
        for( j = i; j < N; j++){
            if( A[j] < A[minj]) minj = j;
        }

        if(i != minj){
            v = A[i];
            A[i] = A[minj];
            A[minj] = v;
            c++; // count up
        }
    }

    /* print sorted sequence */
    trace(A, N); 
    /* print the number of swap operations */
    printf("%d\n",c);
}

/* main function */
int main(){
    int N, i;
    int A[100];

    scanf("%d", &N);
    for( i = 0; i < N; i++) scanf("%d", &A[i]);

    SelectionSort(A, N);

    return 0;    
}
