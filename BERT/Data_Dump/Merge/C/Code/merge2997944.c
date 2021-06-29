#include <stdio.h>
#define v 500000
#define V 2000000000

int L[v/2+2], R[v/2+2];
int c;

void merge(int A[], int n, int l, int m, int r)
{
  int i,j,k,n1,n2;

  n1 = m-l;
  n2 = r-m;
  for(i=0; i<n1; i++)
    L[i] = A[l+i];
  for(i=0; i<n2; i++)
    R[i] = A[m+i];

  L[n1] = R[n2] = V;

  i = 0;
  j = 0;
  for(k=l; k<r; k++){
    c++;
    if(L[i]<=R[j]) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(int A[], int n, int l, int r)
{
  int m;

  if(l+1<r){
    m = (l+r)/2;
    mergeSort(A, n, l, m);
    mergeSort(A, n, m, r);
    merge(A, n, l, m, r);
  }
}

int main()
{
  int n,i,A[v];

  scanf("%d",&n);
  c = 0;
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A, n, 0, n);

  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",c);

  return 0;
}
