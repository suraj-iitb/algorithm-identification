#include <stdio.h>
#include <string.h>

void insertationSort(int A[],int N){
    int i,j,key;
    for(i=0;i<N;i++){
        key=A[i];
        j=i-1;
        while(j>=0&&A[j]>key){
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=key;
        for(j=0;j<N;j++){
            printf("%d",A[j]);
            if(j<N-1) printf(" ");
        }
        printf("\n");
    }
}

int main(void){
    int A[100],N,i;
    scanf("%d\n",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    insertationSort(A,N);
    return 0;
}
