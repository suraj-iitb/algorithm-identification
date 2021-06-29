#include <stdio.h>

int main()
{
  int i, j, n, minj, swap, flag=0, count=0, A[100];

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
    scanf("%d",&A[i]);

  for( i= 0 ; i<n ; i++ ){
    minj = i;
    for( j=i ; j<n ; j++ ){
      if(A[j]<A[minj]){
	minj = j;
	flag = 1;
      }
    }
    swap = A[i];
    A[i] = A[minj];
    A[minj] = swap;
    if(flag==1){
      count++;
      flag =0;
    }
  }
  for( i=0 ; i<n-1 ; i++ )
    printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);

  return 0;
}
