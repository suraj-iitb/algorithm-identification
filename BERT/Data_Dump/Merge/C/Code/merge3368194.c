/*
  Topic5 ProblemB MergeSort
  n 個の整数を含む数列 S を上の疑似コードに従ったマージソートで昇順に整列するプログラムを作成してください。また、mergeにおける比較回数の総数を報告してください。 
 */

#include<stdio.h>

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(int*, int, int, int, int);
void mergeSort(int*, int, int, int);

int main()
{
  int A[MAX], n, i;
  cnt = 0;

  scanf("%d", &n);
  for(i=0;i<n;i++)
    {
      scanf("%d", &A[i]);
    }

  mergeSort(A, n, 0, n);

  for(i=0;i<n;i++)
    {
      if(i)printf(" ");
      printf("%d", A[i]);
    }
  printf("\n%d\n", cnt);
  
  return 0;
}

void merge(int A[], int n, int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  
  for(i=0;i<n1;i++)
    {
      L[i] = A[left + i];
    }

  for(i=0;i<n2;i++)
    {
      R[i] = A[mid + i];
    }
  
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0; j = 0;

  for(k=left;k<right;k++)
    {
      cnt++;
      if(L[i] <= R[j])A[k] = L[i++];
      else A[k] = R[j++];
    }
}

void mergeSort(int A[], int n, int left, int right)
{
  int mid;
  
  if(left+1 < right)
    {
      mid = (left + right)/2;
      mergeSort(A, n, left, mid);
      mergeSort(A, n, mid, right);
      merge(A, n, left, mid, right);
    }
}

