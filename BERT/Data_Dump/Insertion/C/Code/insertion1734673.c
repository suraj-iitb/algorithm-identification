#include <stdio.h>

int main()
{
  int i,j,N,A[1000],v,n;
 
  scanf("%d\n",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<=N;i++){
    v = A[i];
    j = i - 1;
    for(n=0;n<N-1;n++){
      printf("%d ",A[n]);
    }
    printf("%d",A[N-1]);
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
  
    printf("\n");
  }
  return 0;
}
