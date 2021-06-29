#include <stdio.h>

int selectionSort(int A[],int N){
    int cnt=0;
    int AYUNi;
    int i,j,minj;
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(minj != i) cnt++;
        int tmp;
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
    }
    return cnt;
}

int main(){
    int N,i;
    int A[100];
    int kotae;
    
    scanf("%d",&N);
    for(i = 0; i < N; i++) scanf("%d",&A[i]);

    kotae = selectionSort(A,N);

    for(i = 0; i < N; i++){
        if(i != 0) printf(" ");
        printf("%d",A[i]);
    }

    printf("\n");
    printf("%d\n",kotae);

    return 0;
}

