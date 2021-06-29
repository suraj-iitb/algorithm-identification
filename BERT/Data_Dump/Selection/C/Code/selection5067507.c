#include<stdio.h>

int main(void){
  int i,j,k,t,count=0,N,A[100],minj;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j] < A[minj])
	minj = j;
    }
    t=A[i]; A[i]=A[minj]; A[minj]=t;
    if(i!=minj)
      count++;
  }

  for(i=0;i<N;i++){
    if(i == N-1)
    printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",count);

  return 0;
}
    

  
  

