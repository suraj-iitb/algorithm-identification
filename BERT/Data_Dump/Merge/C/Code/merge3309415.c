#include <stdio.h>
#include <stdlib.h>

#define N 500000
#define INFINITY 1000000001
void merge(int [], int, int, int);
void mergeSort(int [], int, int);

int count=0;

int main(){
  int S[N];
  int n, i;

  scanf("%d", &n);
  if(n > N) exit(1);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
    if(S[i] < 0 || S[i] > 1000000000) exit(1);
  }
  mergeSort(S, 0, n);
  for(i=0; i<n; i++){
    printf("%d",S[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}

void merge(int A[], int left, int mid, int right){
  int n1, n2, i, j, k;
  int *L, *R;
  
  n1 = mid - left;
  n2 = right - mid;
  L = malloc( (n1+1)*sizeof(int) );
  R = malloc( (n2+1)*sizeof(int) );
  for(i=0; i<=n1-1; i++) L[i] = A[left + i];
  for(j=0; j<=n2-1; j++) R[j] = A[mid + j];

  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k=left; k<right; k++){
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
  free(L);
  free(R);
}

void mergeSort(int A[], int left, int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

