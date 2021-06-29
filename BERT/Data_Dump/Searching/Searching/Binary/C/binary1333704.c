#include<stdio.h>
#define MAX 100000

int binarySearch(int[], int, int);

main()
{
  int i, n1, n2, S[MAX], T[MAX], count=0;
  
  scanf("%d", &n1);
  for(i=0; i<n1; i++)
    {
      scanf("%d", &S[i]);
    }
  
  scanf("%d", &n2);
  for(i=0; i<n2; i++)
    {
      scanf("%d", &T[i]);
    }
  
  for(i=0; i<n2; i++)
    {
      count += binarySearch(S, T[i], n1);
    }
  printf("%d\n", count);
  
  return 0;
}

int binarySearch(int A[], int key, int n)
{
  int left=0, right=n, mid;

  while(left < right)
    {
      mid = (left + right) / 2;

      if(A[mid] == key)
	{
	  return 1;
	}
      else if(key < A[mid])
	{
	  right = mid;
	}
      else
	{
	  left = mid + 1;
	}
    }

  return 0;
}
