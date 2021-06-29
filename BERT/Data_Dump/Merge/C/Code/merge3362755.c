#include <stdio.h>
#define N 500000
#define SENTINEL 2000000000

void merge(int *,int,int,int,int);
void mergeSort(int *,int,int,int);

int cnt;
int L[N/2+2],R[N/2+2];

int main()
{
  int n,A[N],i;
  cnt = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
{
  scanf("%d",&A[i]);
}
mergeSort(A,n,0,n);
for(i=0;i<n;i++)
{
  printf("%d",A[i]);
  if(i!=n-1)
    printf(" ");
}
printf("\n");
printf("%d\n",cnt);
return 0;
}
void merge(int *A,int n,int left,int mid,int right)
{
  int i,j,k,n1, n2;
  n1 = mid - left ;
  n2 = right - mid;
  for(i=0;i<n1;i++)
    L[i] = A[left + i];
  for(i=0;i<n2;i++)
    R[i] = A[mid + i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0;
  j = 0;
  for(k=left;k<right;k++)
    {
      cnt++;
      if(L[i] <= R[j])
        {
          A[k] = L[i++];
        }
      else
        {
          A[k] = R[j++];
        }
    }
}
void mergeSort(int *B,int n,int left,int right)
{
  int mid;
  if(left+1 < right)
  {
    mid = (left + right)/2;
     mergeSort(B,n,left,mid);
     mergeSort(B,n,mid,right);
    merge(B,n,left,mid,right);
  }
}

