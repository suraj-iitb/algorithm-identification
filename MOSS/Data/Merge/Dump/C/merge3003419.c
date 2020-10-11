#include <stdio.h>
#define INFTY 2000000000
int count=0;

int mergeSort(int x[ ], int left, int right);
int merge(int x[ ], int left, int mid, int right);

int mergeSort(int x[ ], int left, int right){
   int mid;
   if (left+1 < right){
      mid = (left + right) / 2;
      mergeSort(x, left, mid);
      mergeSort(x, mid, right);
      merge(x, left, mid, right);
   }
}

int merge(int A[ ], int left, int mid, int right){
  int n1, n2, i, j, k;
   n1 = mid - left;
   n2 = right - mid;
   int L[n1+1], R[n2+1];
   for(i=0;i<n1;i++) L[i] = A[left + i];
   for(i=0;i<n2;i++) R[i] = A[mid + i];
   L[n1]=INFTY;
   R[n2]=INFTY;
   i = 0;
   j = 0;
   for(k=left;k<right;k++){
      if(L[i] <= R[j]){
         A[k] = L[i];
         i = i + 1;
      }
      else{
         A[k] = R[j];
         j = j + 1;
      }
      count++;
   }
}

int main(void){
int n, i, left, right;
    scanf("%d", &n);
    int x[n];
    for(i=0;i<n;i++)scanf("%d", &x[i]);

    mergeSort(x, 0, n);

    for(i=0;i<n-1;i++)printf("%d ", x[i]);
    printf("%d", x[i]);
    printf("\n");
    printf("%d\n", count);
    return 0;
}
