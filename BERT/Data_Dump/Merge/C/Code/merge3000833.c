#include<stdio.h>
#include<stdlib.h>
#define S 1000000000
#define N 500000

int count =0;
void merge(int A[], int left, int mid, int right)
{
  int n1,n2,i,j,k,*L,*R;
  n1 = mid - left;
  n2 = right - mid;
  L = (int *)malloc(sizeof(int)*(n1+1));
  R = (int *)malloc(sizeof(int)*(n2+1));
  for(i = 0; i<=n1-1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i<=n2-1; i++){
    R[i] = A[mid + i];
  }
  L[n1] = S;
  R[n2] = S;
  i = 0;
  j = 0;
  for(k = left; k<=right-1; k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  }
  free(L);
  free(R);
}
void mergeSort(int A[], int left, int right)
{
  int i,mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
      }
}
int main()
{
  int i,n,A[N];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}

