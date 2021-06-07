#include <stdio.h>

int main()
{
  int n[10000];
  int q[500];
  int i=0,k,a,b,count=0;
  
  //入力
  scanf("%d",&a);
  for(k=0;k<a;k++)
    {
      scanf("%d",&n[k]);
    }
  scanf("%d",&i);
  for(k=0;k<i;k++)
    {
      scanf("%d",&q[k]);
    }

  //数値の探索
  for(k=0;k<i;k++)
    {
      for(b=0;b<a;b++)
	{
	  if(q[k]==n[b])
	    {
	      count++;
	      break;
	    }
	}
    }
  printf("%d\n",count);
  return 0;
}

