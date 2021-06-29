#include <stdio.h>
#define N 1000000
int main()
{

  int i, j, num=0, n, q, key;
  int S[N], T[N];
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i = 0 ; i < q ; i++)
    {
      scanf("%d",&T[i]);
    }

  for(i = 0 ; i < q ; i++)
    {
      key = T[i];
  for(j = 0 ; j < n ; j++)
    {
      if(key == S[j]){
	num++;
	break;
      }
    }

  }
    
      printf("%d\n",num);
  return 0;
}
