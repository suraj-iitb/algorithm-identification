#include <stdio.h>

int S[1000000],n;

int binarySearch(int key)
{
  int left = 0;
  int right = n;
  int mid;
         while(left < right)
           {
             mid = (left + right) / 2;
               if (S[mid] == key)return 1;
               if (key > S[mid]) left = mid +1;
               else if (key < S[mid])right = mid;
           }
  return 0;
}

int main(void)
{
  int i,q,key;
  int cnt = 0;
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i = 0;i < q;i++)
    {
      scanf("%d",&key);
      if (binarySearch(key))cnt++;
    }
  printf("%d\n",cnt);
return 0;
}
