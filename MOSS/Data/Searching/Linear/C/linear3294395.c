#include<stdio.h>
int main(void)
{
  int i,j,n,q,S[100000],T[100000],C=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
          for(j=0;j<i;j++)
    {
      if(S[i]==S[j])
        {
          i--;
          n--;
        }
    }
    }
  scanf("%d",&q);
      for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
              for(j=0;j<i;j++)
        {
          if(T[i]==T[j])
            {
              i--;
              q--;
            }
        }
    }
      for(i=0;i<n;i++)
        {
          for(j=0;j<q;j++)
            {
              if(S[i]==T[j])
                {
              C++;
                }
            }
        }

  printf("%d\n",C);
  return 0;
}

