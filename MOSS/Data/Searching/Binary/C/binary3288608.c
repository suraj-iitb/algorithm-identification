#include<stdio.h>

int binarySearch(int,int *,int);

int main()
{
  int i,j,n,q,S[1000000],T[1000000];

  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0;i < q;i++)
    scanf("%d",&T[i]);

  i = 0;

  for(j = 0;j < q;j++)
    {
      if(binarySearch(n,S,T[j]) == 1)
	i++;
    }
  printf("%d\n",i);

  return 0;
}

int binarySearch(int n,int *A,int key)
{
  int left,right,mid;

  left = 0;
  right = n;

  while(left < right)
    {
      mid = (left + right) / 2;

      if(A[mid] == key)
	return 1;
      else if(key < A[mid])
	right = mid;
      else left = mid + 1;
    }
  return 0;
}

