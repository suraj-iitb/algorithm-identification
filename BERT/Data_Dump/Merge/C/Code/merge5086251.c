#include <stdio.h>
#include <stdlib.h>
#define INFTY 2000000000

int count=0;
void Merge(int * , int , int , int);
void MergeSort(int * , int , int);

int main(void)
{
  int A[500000],left,right,mid,n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);


  MergeSort(A,0,n);

  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d",A[i]);
  printf("\n%d\n",count);
  return 0;
}

void Merge(int *A, int left, int mid,int right)
{
  int n1,n2,i,k,j;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1] ,R[n2+1];
  for (i = 0; i<= n1-1;i++)
    L[i] = A[left + i];
  for (i = 0;i<= n2-1;i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left ;k <= right-1;k++)
    if (L[i] <= R[j])
      {
           A[k] = L[i];
        i = i + 1;
        count++;
      }
    else
      {
        A[k] = R[j];
        j = j + 1;
        count++;
      }
}

void MergeSort(int *A, int left, int right)
{
  int mid;
  if (left+1 < right)
    {
      mid = (left + right)/2;
      MergeSort(A, left, mid);
      MergeSort(A, mid, right);
      Merge(A, left, mid, right);
    }

}

