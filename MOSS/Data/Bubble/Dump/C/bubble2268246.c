#include <stdio.h>

int main()
{
  int j, A[100], N, v, flag, count;

  scanf("%d",&N);
  for(j=0; j<N; j++){
    scanf("%d",&A[j]);
  }

  flag=1;
  count=0;

  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	v=A[j];
	A[j]=A[j-1];
	A[j-1]=v;
	count++;
	flag=1;
      }
    }
  }
  for(j=0;j<N;j++){
    if(j>0) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n%d\n",count);
  return 0;
}
