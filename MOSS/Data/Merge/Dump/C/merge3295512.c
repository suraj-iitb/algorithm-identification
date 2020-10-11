#include<stdio.h>
#define N_MAX 500000
#define LAST 2000000000

int L[(N_MAX/2)+2];
int R[(N_MAX/2)+2];
int count;

void merge(int A[], int n, int left, int mid, int right){
  int i,j,k;
  int n1,n2;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }

  for(j = 0; j < n2; j++){
    R[j] = A[mid + j];
  }

  L[n1] = R[n2] = LAST;

  i=0;
  j=0;

  for(k = left; k < right; k++){
    count++;
    if(L[i] <= R[j]) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

  void mergeSort(int A[], int n, int left, int right){
    if( left+1 < right ){
      int mid = (left + right)/2;
      mergeSort(A,n,left,mid);
      mergeSort(A,n,mid,right);
      merge(A,n,left,mid,right);
    }
  
  }

int main(){
  int A[N_MAX], n, i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,n,0,n);

  for(i=0; i<n; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  printf("%d\n",count);

  return 0;
}

