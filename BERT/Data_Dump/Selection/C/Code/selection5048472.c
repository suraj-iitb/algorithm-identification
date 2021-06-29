#include<stdio.h>

//出力
void trace(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}
//選択ソート
int selectionSort(int A[],int N){
    int i,j,k,minj;
    int count;

    count = 0;

    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        k = A[i];
            A[i] = A[minj];
            A[minj] = k;
            if(minj != i) count++;
    }

    return count;
}

int main() {
    int N,i,j;
    int count;
    int A[100];

    scanf("%d", &N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);

    count = selectionSort(A,N);
    trace(A,N);
    printf("%d\n",count);

    return 0;
}
