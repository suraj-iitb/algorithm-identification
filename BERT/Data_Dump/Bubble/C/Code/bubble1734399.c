#include <stdio.h>

#define N 100

int main(){
  int n, i, j, A[N];
  int swap, count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
 
  for(i=0;i<n-1;i++)
    for(j=n-1;j>i;j--)
      if(A[j]<A[j-1]){
	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
	count++;
      }

  printf("%d",A[0]);
  for(i=1;i<n;i++)
    printf(" %d",A[i]);

  printf("\n%d\n",count);

  return 0;
}
