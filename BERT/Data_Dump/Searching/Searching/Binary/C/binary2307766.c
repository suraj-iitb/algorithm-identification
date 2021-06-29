#include <stdio.h>
#define Max 100000
#define Min 50000

int BinarySearch(int );

int n,S[Max],T[Min];

int main()
{
  int i,q,a,sum=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }

  scanf("%d",&q);

  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
    }

  for(i=0;i<q;i++)
    {
      a = BinarySearch(T[i]);

      if(a == T[i]) sum++;
    }

  printf("%d\n",sum);

  return 0;
}

int BinarySearch(int key)
{
  int left = 0;
  int right = n;
  int mid;
  while (left < right)
    {
      mid = (left + right) / 2;
      if (S[mid] == key) return S[mid];
      else if (key < S[mid])  right = mid;
      else left = mid + 1;  
    }
  return -1;
}
