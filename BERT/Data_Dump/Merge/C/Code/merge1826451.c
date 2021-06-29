#include <stdio.h>
#include <stdlib.h>
#define INF 1000000001

int A[500000];
int L[250001], R[250001];
int cnt = 0;

int merge(int left, int mid, int right)
{
  int i, j, k;
  int n1, n2;
 
  n1 = mid - left;
  for(i = 0; i < n1; i++)
    {
      L[i] = A[left + i];
    }
  L[n1] = INF;
  
  n2 = right - mid;
  for(i = 0; i < n2; i++)
    {
      R[i] = A[mid + i];
    }
  R[n2] = INF;

  i = 0;
  j = 0;
  for(k = left; k < right; k++)
    {
      cnt++;
      if(L[i] <= R[j])
	    {
	    A[k] = L[i];
	    i = i + 1;
	    }
      else
	    {
	    A[k] = R[j];
	    j = j + 1;
	    }
    }
}

void mergeSort(int left, int right)
{
  int mid;

  if(left + 1 < right)
    {
      mid = (left + right)/2;
      mergeSort(left, mid);
      mergeSort(mid, right);
      merge(left, mid, right);
    }
}

int main()
{
  int i;
  int n;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf("%ld", &A[i]);
    }

  mergeSort(0, n);

  for(i = 0; i < n - 1; i++)
    {
      printf("%ld ", A[i]);
    }
  printf("%d\n%d\n", A[n - 1], cnt);

  return 0;
}
