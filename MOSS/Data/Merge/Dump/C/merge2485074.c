#include<stdio.h>
#define MAX 500000
#define BIG 1000000000
int L[MAX/2+2],R[MAX/2+2];
int count=0;
void merge(int A[], int n,int left, int mid, int right);
void mergeSort(int A[],int n, int left,int right);

int main() {
  int A[MAX],i,n;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) scanf("%d\n", &A[i]);

  mergeSort(A,n,0,n);

   for(i=0;i<n;i++) {
     if(i != 0) printf(" ");
     printf("%d",A[i]);
   }
   printf("\n");
   printf("%d\n", count);
   return 0;
}

void merge(int A[], int n,int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
int i = 0,j = 0,k=0;
  for(i = 0;i<n1;i++) L[i]=A[left+i];
  for(i = 0;i<n2;i++) R[i]=A[mid+i];
  L[n1] = BIG;
  R[n2] = BIG;
  i=0;j=0;
  for(k=left;k < right;k++) {
    count++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
}
}

void mergeSort(int A[],int n, int left,int right){
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(A,n, left, mid);
    mergeSort(A,n, mid, right);
    merge(A, n, left, mid, right);
  }
  }
