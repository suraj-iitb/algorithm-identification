#include<stdio.h>

int main(){

  int i,j,N,min,tmp,count=0,A[101];

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    min=i;
    for(j=i;j<N;j++){
      if(A[j]<A[min]){
	min=j;
      }
    }
      tmp=A[i];
      A[i]=A[min];
      A[min]=tmp;
      if(i!=min)count++;
  }

  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);

  printf("%d\n",A[i]);
  printf("%d\n",count);

  return 0;
}
