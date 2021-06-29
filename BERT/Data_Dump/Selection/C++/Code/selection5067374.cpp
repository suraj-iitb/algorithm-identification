#include<stdio.h>
int main()
{
  int A[100],i,j,k,N,minj,flag=0;

  scanf("%d",&N);
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    if(minj!=i){
    k=A[i];
    A[i]=A[minj];
    A[minj]=k;
    flag++;
    }
  }

  for(i=0;i<N;i++){
    if(i!=N-1) printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",flag);
}

