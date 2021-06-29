#include <stdio.h>

int main()
{
  int S[10000],num,num2,i,j,count=0,t,match[10];


  scanf("%d",&num);
  for(i=0;i<num;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&num2);
  for(i=0;i<num2;i++)
    {
      scanf("%d",&t);
      for(j=0;j<num;j++)
	{
	  if(S[j]==t)
	    {
	      count++;
	      break;
	    }
	}
      
    }
  printf("%d\n",count);
  
 
  return 0;
}












