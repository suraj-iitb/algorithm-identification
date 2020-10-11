#include<stdio.h>
#define M 100

int main(){
  int i, j, N, minj, A[M],v,count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
	minj=j;
    }
      v=A[i];
      A[i]=A[minj];
      A[minj]=v;
      if(i!=minj)
      count++;
  }
    printf("%d",A[0]);
      for(i=1;i<N;i++)
    printf(" %d",A[i]);
      printf("\n%d\n",count);






  return 0;
  }

