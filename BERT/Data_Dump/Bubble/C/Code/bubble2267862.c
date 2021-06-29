#include <stdio.h>

int main()
{
  int flag, swap, count=0, i, j, n, A[100];

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
    scanf("%d",&A[i]);

  flag=1;
  while(flag){
    flag = 0;
    for( j=n-1 ; j>0 ; j-- ){
      if(A[j]<A[j-1]){
	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
	count++;
	flag = 1;
      }
    }
  }
  for( i=0 ; i<n-1 ; i++ )
    printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);

  return 0;
}
