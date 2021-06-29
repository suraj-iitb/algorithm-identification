#include<stdio.h>
main(){
  int i,j,count=0,n,a;
  int A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<=n-1;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      a=A[j];
	      A[j]=A[j-1];
	      A[j-1]=a;
	      count++;
	    }
	}
    }
  for(i=0;i<n;i++)
    {
      printf("%d",A[i]);
      if(i<n-1) printf(" ");
    }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
