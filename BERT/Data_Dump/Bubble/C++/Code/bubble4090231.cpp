#include <stdio.h>
void trace(int A[], int N){
    for (int i = 0; i < N; i++){
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

/* バブルソート */
int bubbleSort(int A[], int N){
    int flag, j, temp, count;
    flag = 1;
    count = 0;
    while(flag){
        flag = 0;
        for (j = 1; j < N; j++){
            if (A[j] < A[j - 1]){
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = 1;
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    int N, i, count;
    int A[100];
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    count = bubbleSort(A, N);
    trace(A, N);
    printf("%d\n", count);

    return 0;
}

