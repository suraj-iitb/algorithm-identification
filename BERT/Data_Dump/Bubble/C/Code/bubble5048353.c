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
//バブルソート
int bubbleSort(int A[],int N){
    int j,k,flag;
    int count;

    count = 0;
    flag = 1;

    while(flag){
        flag = 0;
        for(j=N-1;j>0;j--){
            if(A[j] < A[j-1]){
                k = A[j];
                A[j] = A[j-1];
                A[j-1] = k;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N,i,j;
    int count;
    int A[100];

    scanf("%d", &N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);

    count = bubbleSort(A,N);
    trace(A,N);
    printf("%d\n",count);

    return 0;
}
