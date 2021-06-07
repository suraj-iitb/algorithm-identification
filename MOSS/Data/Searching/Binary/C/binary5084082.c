#include <stdio.h>

#define N 100000
#define M 50000

int binary(int,int *,int);

int main()
{
  int n,q,s[N],t[M],i,j,key,x=0;

  scanf("%d",&n);
  for(i=0 ; i < n ; i++)
    scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0 ; i < q ; i++)
    scanf("%d",&t[i]);

  for(i=0 ; i < q ; i++)
    {
      key = t[i];
      j = i-1;
      while(j >= 0 && t[j] > key)
        {
          t[j+1] = t[j];
          j--;
        }
      t[j+1] = key;
    }

  for(i=0 ; i < n ; i++)
    {
      if(s[i+1] == s[i]) continue;
      key=binary(q,t,s[i]);
      if(key == 1) x++;
    }
  printf("%d\n",x);

  return 0;
}
int binary(int q,int *t,int y)
{
  int left=0,right=q,mid;

  while(left < right)
    {
      mid = (left + right)/2;
      if(y == t[mid]) return 1;
      else if(y > t[mid]) left = mid + 1;
      else right = mid;
    }
  return -1;
}
