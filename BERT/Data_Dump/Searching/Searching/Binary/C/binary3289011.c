#include <stdio.h>

int main()
{
  int n,q,i,j,l,r,m,key,count = 0,temp;
  scanf("%d",&n);
  int S[n];
  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  int T[q];
  for(i = 0;i < q;i++)
    {
      scanf("%d",&T[i]);
      //printf("test1\n");
    }
  //printf("%d",q);

  /*for(i = 0;i<q;i++)
    {
      printf("%d",T[i]);
      }*/

  for(i = 0;i < q;i++)
    {
      key =T[i];
      l = 0;
      r = n;
      while(l < r)
	{
	  m = (l + r)/2;
	  //printf("m=%d\n",m);
	  if(key == S[m])
	    {
	      //printf(" %d ",S[m]);
	      count++;
	      break;
	    }
	  if(key > S[m])
	    {
	      l = m + 1;
	    }
	  else if(key <S[m])
	    {
	      r = m;
	    }
	}
      //printf("count%d",count);
    }
  printf("%d\n",count);
  return 0;
}

