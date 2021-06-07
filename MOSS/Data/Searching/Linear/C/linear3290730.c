#include <stdio.h>
#define n 10000
#define q 500
int main()
{
  int S[n],T[q],C=0,es,et,i,j,k,flag;
  scanf("%d",&es);
  for(i=0;i<es;i++)
    scanf("%d",&S[i]); 
  scanf("%d",&et);
  for(i=0;i<et;i++)
    scanf("%d",&T[i]);
  for(i=0;i<es;i++)
    {
      flag=0;
      for(j=0;j<et;j++)
	{
	  for(k=0;k<i;k++)
	    {
	      if(S[i]==S[k])
		{
		  flag=1;
		  break;
		}
	    }
	  if(S[i]==T[j])
	    {
	      if(flag==1) break;
	      C++;
	    }
	}
    }
  printf("%d",C);
  printf("\n");
  return 0;
}

