#include<stdio.h>
main(){
  int i,j,mini=0,a,n,count=0;
  int A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<=n-1;i++)
    {
      mini=i;
      for(j=i;j<=n-1;j++)
	{
	  if(A[j]<A[mini])
	    {
	      mini=j;
	    }
	}
      if(A[i]>A[mini]) count++;
      a=A[i];
      A[i]=A[mini];
      A[mini]=a;
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
