#include <stdio.h>

int main()
{
  int A[100],n,i,minj,j,k,c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  for(i=0;i<n-1;i++)
    {
      minj = i;
      for(j=i;j<=n-1;j++)
	{
	  if(A[j] < A[minj])minj=j;
	}
      if(A[i]>A[minj]){
      k=A[i];
      A[i]=A[minj];
      A[minj]=k;
      c++;
      }
    }
   for(i=0;i<n-1;i++)printf("%d ",A[i]);
   printf("%d\n",A[i]);
   printf("%d\n",c);
   return 0;
}

