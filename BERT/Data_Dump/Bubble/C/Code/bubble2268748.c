#include <stdio.h>

int main()
{
  int i,j,n,flag=1,temp=0,num=0;

  scanf("%d",&n);

  int A[n];
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  i=0;
  while(flag){
    flag = 0;
    for(j=n-1;j>=i+1;j--)
      {
	if(A[j]<A[j-1])
	  {
	    temp = A[j];
	    A[j] = A[j-1];
	    A[j-1] = temp;
	    flag = 1;
	    num++;
	  }
      }
    i++;
  }
  for(j=0;j<n-1;j++)
    {
      printf("%d ",A[j]);
    }
  printf("%d\n",A[j]);
  printf("%d\n",num);
  return 0;
}
