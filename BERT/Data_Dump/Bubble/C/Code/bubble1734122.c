#include <stdio.h>
int main()
{
  int N,A[100],i,j,flag,a,count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  flag = 1;
  i=0;
  while(flag){
    flag=0;
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1]=a;
	count++;
	flag=1;
      }
    }
    i++;
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);

  printf("%d\n",count);

  return 0;
}
