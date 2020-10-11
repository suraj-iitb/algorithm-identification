#include<stdio.h>
 
int main(){
    int i, j;
    int count;
    int N;
    scanf("%d\n", &N);
 
    int A[N];
    for(i = 0; i < N; ++i)
        scanf("%d", &A[i]);
     
    count = 0;
    //selectionSort(A, N)
    for(i = 0; i < N; ++i) {
        int minj = i;
        for(j = i; j < N; ++j) {
            if(A[j] < A[minj])
                minj = j;
        }
        if(i != minj) {
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            count++;
        }
    }
     
    for(i = 0; i < N; ++i) {
        if(i == N-1)
            printf("%d\n", A[i]);
        else
            printf("%d ", A[i]);
    }
    printf("%d\n", count);
    return 0;
}
