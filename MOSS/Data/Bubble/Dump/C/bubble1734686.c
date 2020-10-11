#include <stdio.h>
#define N 100
int main()
{
  int i, j, bubble[N], temp, n, ccount=0, count = 0, flag;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&bubble[i]);
    }
  for(i = 0 ; i < n ; i++ )
    {
  flag = 1;
  while(flag)
	{
	  flag = 0;
	  for(j = n - 1 ; j > 0 ; j--)
	    {
	      if(bubble[j] < bubble[j-1])
		{
		  temp = bubble[j];
		  bubble[j] = bubble[j-1];
		  bubble[j-1] = temp;
		  ccount++;
		  flag = 1;
		}	      
	}
	}
    }
      for(i = 0 ; i < n ; i++)
	{
	  if(i == n - 1){
	    printf("%d\n",bubble[i]);
	  } else{
printf("%d ",bubble[i]);
	  }
	}
      printf("%d\n",ccount);

  return 0;
}
