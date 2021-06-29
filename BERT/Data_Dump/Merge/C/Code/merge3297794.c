#include<stdio.h>

#define MAX 500000
#define INFTY 2000000000

int g_count;

void merge(int [], int, int, int);
void mergeSort(int [], int, int);

int main(){
  int A[MAX], n, i;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);

  mergeSort(A,0,n);

  for(i = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n");

  printf("%d\n",g_count);
  
  return 0;
}

void merge(int A[], int left, int mid, int right){
  int n1, n2,i,j,k;
  int L[MAX/2+2],R[MAX/2+2];

  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid+i];
  L[n1] = R[n2] = INFTY;

  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    g_count++;
    if(L[i] <= R[j]) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(int A[], int left, int right){
  if(left+1 < right){
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A ,left, mid, right);
  }
}


