#include<stdio.h>
void bubbleSort(int A[100], int n){
    int j, flag, swap;
    int cnt = 0;
    flag = 1;
    while(flag){
        flag = 0;
        for(j=n-1; j>0; j--){
            if(A[j] < A[j-1]){
                swap = A[j-1];
                A[j-1] = A[j];
                A[j] = swap;
                flag = 1;
                cnt++;
            }
        }
    }
    printf("%d", A[0]);
    for(j=1; j<n; j++){
        printf(" %d", A[j]);
    }
    printf("\n");
    printf("%d\n", cnt);
}

int main(){
    int i, N, A[100];

    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    bubbleSort(A,N);

    return 0;
}
