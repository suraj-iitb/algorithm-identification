#include <stdio.h>
#include <stdlib.h>

void Count(int*count)
{
  (*count)++;
}

void Merge(int A[], int p,int q,int r,int B[],int *count)
{
  int t;
  int i,left, right,k;
  k = p; left = p; right = q+1;
  while(k <= r)
  {
    if(right>r) t = A[left++];
    else if(left>q) t = A[right++];
    else if(A[left]<=A[right]) t = A[left++];
    else t =A[right++];
    B[k++]=t;
    Count(count);
  }
  for (i=p;i<=r;i++) A[i]=B[i];
}

void Merge_Sort(int A[], int p, int r,int B[], int *count)
{
  if(p<r)
  {
    int q = (p+r)/2;
    Merge_Sort(A,p,q,B, count);
    Merge_Sort(A,q+1,r,B, count);
    Merge(A,p,q,r,B,count);
    //Count(count);
  }
}

int main()
{
  int r;
  scanf("%d", &r);
  int *count, A[r], B[r];
  count = malloc(sizeof(int));
  *count=0;
  for(int i=0;i<r;i++)
  {
    scanf("%d", &A[i]);
  }
  Merge_Sort(A,0,r-1,B, count);
  for(int i=0;i<r-1;i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d",A[r-1]);
  printf("\n%d\n", *count);
  return 0;
}
