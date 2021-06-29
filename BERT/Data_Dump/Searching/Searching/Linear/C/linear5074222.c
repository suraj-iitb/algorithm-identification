#include <stdio.h>
#include <stdlib.h>
int main(void)
{
        int n,q,*S,*T,i,key,j,count=0;
        scanf("%d",&n);
        S=(int *)malloc(n * sizeof(int));
        for(i=0;i<n;i++)
          {
            scanf("%d",&S[i]);
          }
        scanf("%d",&q);

        T=(int *)malloc(q * sizeof(int));
        for(i=0;i<q;i++)
          {
            scanf("%d",&T[i]);
          }

        for(j=0;j<q;j++)
          {
            i = 0;
            key = T[j];
            while (S[i] != key && i<n)
              {
                i++;
              }
            if (i == n)
              continue;
            else count++;
          }
        printf("%d\n",count);
        return 0;
}


