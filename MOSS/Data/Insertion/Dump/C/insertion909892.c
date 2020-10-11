#include <stdio.h>
int main()
{
  int i,j=0,k;
  int key;
  int A[100];
  int ans,num=0;

  scanf("%d",&num);
  for(i=0;i<num;i++)
    {
      ans=scanf("%d",&A[i]);
    }

  for(i=0;i<num;i++)
    {
      key=A[i];
      j=i-1;
      while(j>= 0 && A[j]>key)
	{
	  A[j+1] = A[j];
	  j--;
	  A[j+1] = key;
	}
      for(k=0;k<num;k++)
	{
	  if(k==num-1) printf("%d",A[k]);
	  else printf("%d ",A[k]);
	}
      printf("\n");
    } 
return 0;
}
