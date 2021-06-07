#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int n,q,*S,*T,i,j,left,right,mid,key,flag,count=0;

  scanf("%d",&n);
  S=(int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  T=(int *)malloc(q * sizeof(int));
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  for(j=0;j<q;j++)
    {
      key=T[j];
      left = 0;
      right = n;
      flag=0;
      while (left < right)
        {
          mid = (left + right) / 2;
          if (S[mid] == key)
            {
              flag=1;
              break;
            }
          else if (key < S[mid])
            right = mid;
          else
            left = mid + 1;
        }
      if(flag == 1)count++;
    }
  printf("%d\n",count);
  return 0;
}
