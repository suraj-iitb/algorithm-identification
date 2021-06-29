#include <stdio.h>
#include <stdlib.h>

#define INFTY 1000000009
#define N 500005
int count;

void merge(int A[],int left,int mid, int right){
  int i,j,k,n1,n2,*L,*R;
  n1 = mid - left;
  n2 = right - mid;
  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));
  for(i=0; i<n1; i++) L[i] = A[left + i];
  for(i=0; i<n2; i++) R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k=left; k<right; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  } 

  free(L);
  free(R);
}


void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}


int main(){
  int i,n,A[N];
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&A[i]);

  mergeSort(A,0,n);

  for(i=0; i<n; i++) {
    printf("%d",A[i]);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",count);

  return 0;

}
