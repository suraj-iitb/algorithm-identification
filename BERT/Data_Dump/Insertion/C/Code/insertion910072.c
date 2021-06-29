#include <stdio.h>
main(){
  int i,j,key,n,k;
  int A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
      printf("%d",A[i]);
      if(i<n-1) printf(" ");
    }
  printf("\n");
  for(i=1;i<=n-1;i++)
    {
      key=A[i];
      j=i-1;
      while(j>=0&&A[j]>key)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=key;
      for(k=0;k<n;k++)
	{
	  printf("%d",A[k]);
	  if(k<n-1) printf(" ");
	}
      printf("\n");
    }
  return 0;
}
