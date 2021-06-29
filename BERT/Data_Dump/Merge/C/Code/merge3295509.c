#include<stdio.h>
#define MAX 500000
#define INF 1e9

int Left[MAX/2+2];
int Right[MAX/2+2];
int cnt = 0;

void merge(int A[], int l, int mid, int r)
{
  int i,k;
  
  int n1 = mid - l;
  int n2 = r - mid;

  for(i=0;i < n1;i++) Left[i] = A[l+i];
  for(i=0;i < n2;i++) Right[i] = A[mid+i];
  Left[n1] = Right[n2] = INF;

  int ii=0,jj=0;
  for(k = l;k < r;k++){
    if(Left[ii] <= Right[jj]) A[k] = Left[ii++];
    else A[k] = Right[jj++];
    cnt++;
  }
}

void mergesort(int A[], int left, int right)
{
  if( left+1 < right ){
    int mid = (right + left)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main()
{
  int i;
  int A[MAX+1];
  int n;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&A[i]);

  mergesort(A, 0, n); //left = 0, right = n

  for(i = 0;i < n;i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  printf("%d\n",cnt);
  return 0;
}
  
  

