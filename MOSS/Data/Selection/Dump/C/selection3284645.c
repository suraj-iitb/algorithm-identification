#include "stdio.h"

int main(){

    int A[100],N,i,j,k,minj,count=0;
        scanf("%d",&N);
    for(i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
    
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
            minj=j;
            }
        }
    if(i!=minj)
    count++;
    k=A[i];
    A[i]=A[minj];
    A[minj]=k;
    }
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i<N-1)
        printf(" ");
            }
    printf("\n%d\n",count);
    return 0;
        }

