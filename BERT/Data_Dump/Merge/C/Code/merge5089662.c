#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long merge(int [],int ,int , int);
long mergeSort(int [],int ,int);

int main()
{
  int left,right;
  int n,i;
  int *S;
  long cnt;

  scanf("%d",&n);
  if(!(n<=500000)) exit(1);

  S =(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
      if(!(S[i]>=0 && S[i]<=1000000000)) exit(2);
    }
  right = n;
  left = 0;

  cnt = mergeSort(S,left,right);

  for(i=0;i<n-1;i++)
    {
      printf("%d ",S[i]);
    }
  printf("%d\n",S[i]);
  printf("%ld\n",cnt);

  free(S);
  return 0;
}
long merge(int A[],int left,int mid,int right)
{
  int n1,n2;
  int *L,*R;
  static long cnt=0;
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));

  for(i = 0;i<n1;i++)
    {
      L[i] = A[left + i];
    }
  for( i = 0;i<n2;i++)
    {
      R[i] = A[mid + i];
    }
  L[n1] = ((int)INFINITY);
  R[n2] = ((int)INFINITY);
  i = 0;
  j = 0;
  for(k=left;k<right;k++)
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
      if(!(A[k]>=0 && A[k]<=1000000000)) exit(2);
    }
  free(L);
  free(R);
  return cnt;
}

long mergeSort(int A[],int left,int right)
{
  long cnt=0;
  int mid;
  if(left+1<right)
    {
      mid = (left+right)/2;
      mergeSort(A,left,mid);
      mergeSort(A,mid,right);
      cnt = merge(A,left,mid,right);
    }
    return cnt;
}
