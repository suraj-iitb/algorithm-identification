#include <stdio.h>
#define MAX 500000
#define INFTY 1000000000

int c=0,A[MAX];

void merge(int A[],int left,int mid,int right) {
  int i,j,n1,n2,k,L[MAX/2+1],R[MAX/2+1];
  n1 = mid - left;
  n2 = right - mid;
    for(i = 0 ;i < n1;i++) {
      L[i] = A[left + i];
      }
  for(i = 0;i < n2;i++){
    R[i] = A[mid + i];
  }
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0;
    j = 0;
      
  for(k = left;k < right;k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
      c++;
	}
    else {
      A[k] = R[j];
      j = j + 1;
      c++;
    }
  }
}

void mergeSort(int A[],int left,int right) {
  int mid;
	if(left+1 < right) {
	  mid = (left + right)/2;
          mergeSort(A, left, mid);
	  mergeSort(A, mid, right);
	  merge(A, left, mid, right);
	}
}

int main() {
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0;i<n;i++) {
    printf("%d",A[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
