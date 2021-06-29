#include <stdio.h>

int main()
{
  int A[1000],N,i,j,v;

  scanf("%d",&N);
  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }
  
  for(j=0;j<N-1;j++){
    printf("%d ",A[j]);
    }
  printf("%d\n",A[N-1]);

  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(j=0;j<N-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d\n",A[N-1]);
     
  }
  
  return 0;
}
