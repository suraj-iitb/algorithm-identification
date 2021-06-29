#include<stdio.h>

#define INTMAX 2147483647

int cnt=0;

void merge(int *A, int l, int m, int r)
{
  int n1, n2, L[250010], R[250010], i, j, k;

  n1 = m - l;
  n2 = r - m;

  for(i = 0; i < n1; i++)
  {
    L[i] = A[l+i];
  }

  for(i = 0; i < n2; i++)
  {
    R[i] = A[m+i];
  }

  L[n1] = R[n2] = INTMAX;

  for(k = l, i = j = 0; k < r; k++)
  {
    if(L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
      cnt++;
    }

    else
    {
      A[k] = R[j];
      j++;
      cnt++;
    }
  }
}


void mergeSort(int *A, int l, int r)
{
  int m;

  if(l+1 < r)
  {
    m = (l + r)/2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}

int main()
{
  int n, A[500000], i;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  mergeSort(A, 0, n);

  for(i = 0; i < n-1; i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[i], cnt);

  return 0;
}

