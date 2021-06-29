#include <stdio.h>
#define N 500000

void Merge(int *, int, int, int);
void Merge_Sort(int *, int, int);

int count=0;

int main(void){
  int n,i;
  int A[N];

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&A[i]);
  Merge_Sort(A, 0, n);

  for(i=0; i<n; i++){
    if(i != 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);

  return 0;
}

void Merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  int L[N],R[N];

  n1 = mid -left;
  n2 = right - mid;

  for(i=0; i<n1; i++) L[i] = A[left + i];
  for(i=0; i<n2; i++) R[i] = A[mid + i];

  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = j = 0;

  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
    count++;
  }
}

void Merge_Sort(int *A,int left,int right){
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    Merge_Sort(A, left, mid);
    Merge_Sort(A, mid, right);
    Merge(A, left, mid, right);
  }

}
