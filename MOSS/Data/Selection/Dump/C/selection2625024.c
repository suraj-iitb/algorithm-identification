#include <stdio.h>
#include <stdlib.h>


int selectionSort(int *A,int  N){
int i,j,n,minj,x=0;

 for(i = 0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
                if(A[j]<A[minj]){
                minj=j;
        }}
        if(i!=minj){
        n=A[i];
        A[i]=A[minj];
        A[minj]=n;
        x++;
        }
 }
return x;
}

int main(void){
 int N,x,i;
 int *A;

 scanf("%d",&N);
 A=(int *)malloc(N * sizeof(int));
 for (i=0; i<N;i++){
  scanf("%d",&A[i]);
 }

x=selectionSort(A,N);

printf("%d",A[0]);
 for(i=1;i<N;i++){
  printf(" %d",A[i]);
 }
printf("\n%d\n",x);

free(A);
return 0;
}
