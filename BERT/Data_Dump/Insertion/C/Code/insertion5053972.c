#include<stdio.h>
#define MAX 100

int main(){
    int i,j,N,A[MAX],B;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(j=0;j<N;j++){
            if(j!=N-1)printf("%d ",A[j]);
            else printf("%d\n",A[j]);
    }
    for(i=1;i<N;i++){
        for(j=i;j>=1;j--){
            if(A[j]<A[j-1]){
                B=A[j];
                A[j]=A[j-1];
                A[j-1]=B;
            }
        }
        for(j=0;j<N;j++){
            if(j!=N-1)printf("%d ",A[j]);
            else printf("%d\n",A[j]);
        }
    }
    return 0;

}

