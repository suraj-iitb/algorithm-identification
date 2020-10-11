#include <stdio.h>

#define N 100

int main()
{
  int i,j,k,hako[N],n,count = 0;

  scanf("%d",&n);

  for(i =  0;i < n;i ++)
    {
      scanf("%d",&hako[i]);
    }
  
  for(i = 0;i < n;i ++)
    {
      for(j = 0;j < n - i - 1;j ++)
	{
	  if(hako[j] > hako[j + 1]){
	    k = hako[j];
	  hako[j] = hako[j + 1];
	  hako[j + 1] = k;
	  count ++;
	  }

	}
    }

  for(i = 0;i < n -1 ;i ++)
    {
      printf("%d ",hako[i]);
    }

  printf("%d\n",hako[i]);
  printf("%d\n",count);

  return 0;
}
