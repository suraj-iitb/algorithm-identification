#include <stdio.h>

#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)

void printArray(int A[], int N) {
    rep(i,N-1)
        printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
}

void selectSort(int A[], int N) {
    int count = 0;
    
    for(int i = 0; i < N-1; i++) {
        int min_j = i;
       // 線形探索で、最小値がある要素の添え字を、見つける
        for(int j = i+1; j < N; j++) {
            if( A[j] < A[min_j]) {
                min_j = j;
            }
        }
        if(min_j != i) {
            int work;
            work = A[i]; A[i] = A[min_j]; A[min_j] = work;
            count++;
        }
    }
    printArray(A,N);
    printf("%d\n", count);

}
int main() {
    int A[100];
    int N;

    scanf("%d", &N);
    rep(i,N)
        scanf("%d", &A[i]);
    
    selectSort(A,N);
    
    return 0;
}



