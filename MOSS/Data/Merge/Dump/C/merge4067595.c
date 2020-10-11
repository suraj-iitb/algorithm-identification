#include <stdio.h>
#include <limits.h>

#define SIZE 500000

void merge(int, int, int);
void mergesort(int, int);

int count = 0;
int a[SIZE];

int main()
{
  int n, i, left, right;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
    }
  
  left = 0;
  right = n;

  mergesort(left, right);

  for(i = 0; i < n-1; i++)
    {
      printf("%d ",a[i]);
    }

  printf("%d\n",a[n-1]);

  printf("%d\n",count);

  return 0;
}

void merge(int left, int mid, int right)
{
  int i, j, k, n1, n2, L[SIZE/2+1], R[SIZE/2+1];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++)
    {
      L[i] = a[left + i];
    }

  for(i = 0; i < n2; i++)
    {
      R[i] = a[mid + i];
    }

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  i = 0;
  j = 0;

  for(k = left; k < right; k++)
    {
      if(L[i] <= R[j])
	{
	  a[k] = L[i];
	  i++;
	}
      else
	{
	  a[k] = R[j];
	  j++;
	}
      count++;
    }
}

void mergesort(int left, int right)
{
  int mid;
  
  if(left+1 < right)
    {
      mid = (left + right)/2;
      mergesort(left, mid);
      mergesort(mid, right);
      merge(left, mid, right);
    }
}

