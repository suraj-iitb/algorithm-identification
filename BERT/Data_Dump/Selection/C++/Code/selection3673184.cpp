#include<stdio.h>

int selectionSort(int A[],int N){
    int sw=0;
    int i,j,t;
    int minj;
    for(i=0;i<N-1;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj])  minj=j;
        }
// 入れ替え
        t=A[i];
        A[i]=A[minj];
        A[minj]=t;
        if(i !=minj) sw++;
      
     }
    return sw;
}

int main(){
    int A[100],N,sw;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);

    sw=selectionSort(A,N);

    for(int i=0;i<N;i++){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    } 
    printf("\n");
    printf("%d\n",sw);

    return 0;
}
