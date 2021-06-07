#include <stdio.h>

int A[1000000], n;

int binarySearch(int);

int main()
{
  int i, q, key, m, sum=0;

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &A[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++)
  {
    scanf("%d", &key);
    if(binarySearch(key)==1) sum++;
  }

  printf("%d\n", sum);

  return 0;
}

int binarySearch(int key)
{
  int left=0, right=n, mid;

  while(left<right)
  {
    mid=(left+right)/2;
    if(A[mid]==key) return 1;
    if(A[mid]<key) left=mid+1;
    else if(key<A[mid]) right=mid;
  }

  return 0;
}

