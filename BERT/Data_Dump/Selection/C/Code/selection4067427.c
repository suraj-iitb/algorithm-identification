#include <stdio.h>
void selectionSort(int *,int);
int main(){
    int i,A[100];
    int N;
    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    selectionSort(A, N);
    return 0;
}
void selectionSort(int *A, int N){
    int v=0,j=0,i,t;
    int cnt=0;
    int minj;
    for(i=0; i<=N-1; i++){
        minj = i;
        for(j=i; j<=N-1; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            cnt++;
        }
        v = A[minj];
	    A[minj] = A[i];
	    A[i] = v;
    }   
    for(t=0; t<N-1; t++){
        printf("%d ",A[t]);
    }
    if(t==N-1){
        printf("%d",A[t]);
    }
    printf("\n");
    printf("%d\n",cnt);
}

