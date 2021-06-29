#include <stdio.h>
#include <math.h>

#define N 1000000
#define INFTY 2000000000
 
int A[N], count=0;
 
void merge(int, int, int);
void mergeSort(int, int);
int main()
{
  int n,i;
   
  scanf("%d",&n);
   
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);
 
  mergeSort(0,n);
 
  for(i=0;i<n;i++){
    printf("%d", A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n", count);
   
  return 0;
}
 
void merge(int left, int mid, int right)
{
  int n1, n2, i, j, k, L[N], R[N];

  n1 = mid - left;
  n2 = right - mid;

  for(i=0; i<=n1-1; i++)
    L[i] = A[left + i];

  for(i=0; i<=n2-1; i++)
    R[i] = A[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;

  for(k=left; k<=right-1; k++)
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    } 
    else {
      A[k] = R[j];
      j = j + 1;
      count++;
    }
}

void mergeSort(int left, int right)
{
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}
