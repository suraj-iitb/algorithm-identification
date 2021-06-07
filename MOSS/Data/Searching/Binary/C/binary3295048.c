#include <stdio.h>
#define NOT -1

int Bineary(int key ,int n ,int S[])
{
  int left = 0,mid,right = n;

  while(left < right)
    {
      mid = (left + right) / 2;
      if(S[mid] == key) return mid;
      else if(key < S[mid]) right = mid;
      else left = mid + 1;
    }
      return NOT;
}

 int main()
{
  int i,t = 0,n,q,S[1000000],T[1000000];;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0;i < q;i++) scanf("%d",&T[i]);

  for(i = 0;i < q;i++) if(Bineary(T[i],n,S) != NOT) t++;

  printf("%d\n",t);

  return 0;
}


