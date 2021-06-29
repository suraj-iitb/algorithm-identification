#include<stdio.h>
int A[20000000],B[20000000],C[20000000];
int n;

void CountingSort(int k)
{
  int i,j;
  for(i=0;i<=k;i++)
    {
      C[i]=0;
    }
  for(j=1;j<=n;j++)
    {
      C[A[j]]++;
    }
  for(i=1;i<=k;i++)
    {
      C[i]=C[i]+C[i-1];
    }
  for(j=n;j>=1;j--)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }
}

main(){
  int i,k=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      scanf("%d",&A[i]);
      if(k<A[i])
	k=A[i];
    }
  CountingSort(k+1);
  for(i=1;i<=n;i++)
    {
      printf("%d",B[i]);
      if(i<n)
	printf(" ");
    }
  printf("\n");
  return 0;

}
