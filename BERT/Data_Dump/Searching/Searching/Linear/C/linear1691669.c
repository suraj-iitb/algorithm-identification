#include <stdio.h>
#include <math.h>

#define Max 10000
#define max 500

int main(void){
int n,q,i,j,count=0;

  int S[Max],T[max];
  
  scanf("%d",&n);// ??°???????????´??°????????°???

  for(i = 0; i<n ;i++)//??°?????????????????????
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);// ??°?????´?????´??°????????°q
  for(i = 0; i<q ;i++)//??°???T???????????????
    {
      scanf("%d",&T[i]);
    }

  for (i = 0;i < q;i++)
    {
      for(j = 0;j < n;j++)
        {
          if (S[j] == T[i])
            {
              count++;
              break;
            }
        }

    }
    printf("%d\n",count);
  return 0;
}
