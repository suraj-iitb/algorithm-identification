#include <stdio.h>

void bubbleSort(int A[], int N){
    
    int flag = 1, j, count = 0, i;
    while ( flag ) {
        flag = 0;
        for( j = N-1; 0 < j; --j ){
            if (A[j] < A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1 ;
                count ++;
            }
        }
    }
    for( i = 0; i < N; i++ ){
        printf("%d", A[i]);
        if( i != N-1 ) printf(" ");
    }
    printf("\n");
    printf("%d\n", count);
}

int main() {
    int i, N;
    scanf("%d", &N);
    int A[N];
    for( i = 0; i < N; ++i ) {
        scanf("%d", &A[i]);
    }
    bubbleSort(A, N);
    return 0;
}
