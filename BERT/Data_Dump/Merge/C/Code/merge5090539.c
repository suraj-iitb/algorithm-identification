#include <stdio.h>
#include <stdlib.h>

#define N 500000

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int n, cnt = 0;

int main()
{
  int S[N], i;

  scanf("%d", &n);
  if(n > N) exit(1);

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d", &S[i]);
      if(S[i] < 0 || 1.0e9 < S[i]) exit(2); 
    }

  mergeSort(S, 0, n);

  for(i = 0 ; i < n - 1; i++) printf("%d ", S[i]);
  printf("%d\n%d\n", S[i], cnt);

  return 0;
}

void mergeSort(int *A, int left, int right)
{
  int mid;
  
  if(left + 1 < right)
    {
      mid = (left + right) / 2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }
}

void merge(int *A, int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  int L[N], R[N];
  int i, j, k;

  for(i = 0 ; i < n1 ; i++)
    {
      L[i] = A[left + i];
    }
  for(j = 0 ; j < n2 ; j++)
    {
      R[j] = A[mid + j];
    }
  L[n1] = R[n2] = 1.0e9;

  i = j = 0;
  for(k = left ; k < right ; k++)
    {
      if(L[i] < R[j])
	{
	  A[k] = L[i];
	  i++;
	}
      else
	{
	  A[k] = R[j];
	  j++;
	}
      cnt++;
    }
}

