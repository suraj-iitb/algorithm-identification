#include <stdio.h>
#include <math.h>

int t = 0,L[250002],R[250002];

void marge(int A[],int left,int mid,int right)
{
  int i,j,k,n1,n2;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0;i < n1;i++) L[i] = A[left + i];
  for(i = 0;i < n2;i++) R[i] = A[mid + i];
  L[n1] = 2000000000;
  R[n2] = 2000000000;
  
  i = 0;
  j = 0;
  for(k = left;k < right;k++)
  {
    if(L[i] <= R[j])
    {
      A[k] = L[i++];
      t++;
    }
    else
    {
      A[k] = R[j++];
      t++;
    }
  }
}

void margesort(int A[],int left,int right)
{
  int mid;

  if(left + 1 < right)
  {
    mid = (left + right) / 2;
    margesort(A,left,mid);
    margesort(A,mid,right);
    marge(A,left,mid,right);
  }
}

int main()
{
  int A[500000],n,i;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&A[i]);

  margesort(A,0,n);

  for(i = 0;i < n;i++)
  {
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",t);

  return 0;
}

