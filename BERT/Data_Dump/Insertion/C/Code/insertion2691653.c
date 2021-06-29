#include <stdio.h>

/* out function */
void trace(int A[], int N){
    int i;
    for( i = 0; i < N; i++ ){
        if( i > 0) printf(" "); // single space to separate elments
        printf("%d", A[i]);
    }
    printf("\n");
}

/* insert sort (zero origin) */
void insertSort(int A[], int N){
    int j, i, v;
    for( i = 1; i < N; i++ ){
        v = A[i];
        j = i -1;
        while( j >= 0 && A[j] > v ){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

/* main function */
int main(){
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for( i = 0; i < N; i++) scanf("%d", &A[i]);

    trace(A, N);
    insertSort(A, N);

    return 0;    
}
