#include<stdio.h>

int A[100000],n;

int binarySearch(int);

int main()
{
  int i,q,key;
  int sum = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&A[i]);
    }

  scanf("%d",&q);

  for(i = 0; i < q; i++)
    {
      scanf("%d",&key);
      if(binarySearch(key))sum++;
    }
  printf("%d\n",sum);

  return 0;
}

int binarySearch(int k)
{
  int left = 0;
  int right = n;
  int mid;

  while (left < right)
    {
      mid = (left + right)/2;

      if(k == A[mid])return 1;
      if(k > A[mid])left=mid+1;
      else if(k < A[mid])right = mid;
    }
  return 0;
}

