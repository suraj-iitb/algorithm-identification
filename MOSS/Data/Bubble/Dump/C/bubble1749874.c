#include <stdio.h>
#define N 100
int main(){
  int n,i,j,flag=0,minj;
  int A[N];
 
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<n-1;i++)
    {
      for(j=n-1;j>i;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      minj=A[j-1];
	      A[j-1]=A[j];
	      A[j]=minj;
	      flag=flag+1;
	    }
	}
    }
  for(i=0;i<n-1;i++)
    {
      printf("%d ",A[i]); 
   }
  printf("%d",A[i]);
  printf("\n");
  printf("%d\n",flag);
 
return 0;
}
