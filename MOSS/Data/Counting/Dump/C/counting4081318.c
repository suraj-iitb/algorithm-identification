#include <stdio.h>

int main()
{
  int n=0,i=0,j=0,k=0,flag=0,max=0;
  int A[100000];

  //入力
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&j);
      A[j]++;
      if(max-j < 0)max=j;
    }

  //出力
  for(i=0;i<=max;i++)
    {
      for(k=0;k<A[i];k++)
	{
	  if(flag==0)
	    {
	      printf("%d",i);
	      flag++;
	    }
	  else if(1<=A[i])printf(" %d",i);
	}
    }
  printf("\n");
  return 0;
}

