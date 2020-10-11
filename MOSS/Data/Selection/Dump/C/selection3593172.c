// Selection Sort
#include <stdio.h>

int selectionSort(int A[], int N)
{
    int i, j, minj, tmp, cnt = 0;
    for(i=0; i<N; i++){
        minj = i;
        for(j=i; j<N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            cnt++; 
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
        }
    }
    return cnt; 
}

int main(void)
{
    int N, i;
    scanf("%d", &N);
    int A[N];
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    int cnt = selectionSort(A, N);
    for(i=0; i<N; i++){
        if(i==N-1){
            printf("%d\n", A[i]);
        }else{
            printf("%d ", A[i]);
        }
    }
    printf("%d\n", cnt);

    return 0;
}
