#include <stdio.h>
#define N 10000
#define N2 500

int main()
{
  int i,j,k,l;
  int n,q;
  int S[N],T[N2],U[N2];
  int count=0,flag;;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {   
      scanf(" %d",&S[i]);
    }
  
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {   
      scanf(" %d",&T[i]);
    }
  //  printf("//////////////////////////\n");
  for(i=0;i<n;i++)
    {
      for(j=0;j<q;j++)
	{
	  if(S[i]==T[j])
	    {
	      flag=1;
	      if(k>0)
		{
		  for(l=0;l<k;l++)
		    {
		      if(S[i]==U[l])
			{
			  flag=0;
			}
		    }
		}
	      U[k]=S[i];
	      k++;
	      if(flag==1)
		{
		  count++;
		}
	    }
	  else continue;
	}
    }
  printf("%d\n",count);
  return 0;
}

