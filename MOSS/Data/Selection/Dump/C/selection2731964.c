#include <stdio.h>

int selectionSort(int *, int);

int main()
{
    int i, N, count;
    int A[100];
    
    scanf("%d", &N);
    for(i=0; i < N; i++){
        scanf("%d", &A[i]);
    }
    count = selectionSort(A, N);
    for(i=0; i < N; i++){
        if(i != 0)printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
    
    return 0;
}

int selectionSort(int A[], int N)
{
    int i, j, str, count=0, minj;
    for(i=0; i < N-1; i++){
        minj = i;
        for(j=i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[i] != A[minj]){
            str = A[i];
            A[i] = A[minj];
            A[minj] = str;
            count++;
        }
    }
    return count;
}
