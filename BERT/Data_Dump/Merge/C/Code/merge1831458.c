#include<stdio.h>

#define N 500000
#define INFTY 10000000000

int count=0;

void merge(int A[],int left,int mid,int right);
void mergeSort(int A[],int left,int right);

int main()
{
  int A[N];
  int n,i;
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i < n-1)printf(" ");
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}

void merge(int A[],int left,int mid,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1],R[n2];

  for(i = 0;i <= n1 - 1;i++){
    L[i] = A[left+i];
  }

  for(j = 0;j <= n2 - 1;j++){
    R[j] = A[mid+j];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k = left; k <= right-1; k++){
   if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }

    else{
      A[k] = R[j];
      j++;
      count++;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int i,mid;

  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
