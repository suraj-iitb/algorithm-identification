#include<stdio.h>
#define Max 100

int main()
{

  int i,j,x,N,A[Max],count=0,minj=0;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]) minj = j;
    }
    if(i!=minj){
      x = A[i];
      A[i] = A[minj];
      A[minj] = x;
      count++;
    }
  }
  
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  
  printf("\n%d\n",count);
  
  return 0;
}
