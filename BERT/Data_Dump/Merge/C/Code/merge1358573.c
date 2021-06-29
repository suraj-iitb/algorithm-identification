#include <stdio.h>
#define NM 500000
#define SM 1000000000
void merge(int*, int, int, int);
void mergeSort(int*, int, int);
int num;
main()
{
  int i;
  int left;
  int right;
  int n;
  int S[NM];

  scanf("%d",&n);

  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
    }

  left = 0;
  right = n;
   
  mergeSort(S, left, right);

  for(i = 0;i < n;i++)
    {
      printf("%d",S[i]);
      if(i != n - 1)
	{
	  printf(" ");
	}
    }
  printf("\n");
  printf("%d\n",num);

  return 0;

}

void mergeSort(int *A, int left, int right)
{
  int mid;

  if(left + 1 < right)
    {
      mid = (left + right)/2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }
}

void merge(int *A, int left, int mid, int right)
{
  int n1, n2;
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  int L[n1 + 1];
  int R[n2 + 1];


  for(i = 0;i < n1;i++)
    {
      L[i] = A[left + i];
    }

 
  for(i = 0;i < n2;i++)
    {
      R[i] = A[mid + i];
    }


  L[n1] = SM;
  R[n2] = SM;

  i = 0;
  j = 0;

  for(k = left;k < right;k++)
    {
      if(L[i] <= R[j])
	{
	  A[k] = L[i];
	  i++;
	  num++;
	}

      else
	{
	  A[k] = R[j];
	  j++;
	  num++;
	}
    }
}
