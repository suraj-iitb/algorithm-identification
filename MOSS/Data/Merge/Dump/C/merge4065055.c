#include<stdio.h>
#include<math.h>

int i,n,A[500000],count=0;

void merge(int *A, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];
  for(i=0;i<=n1-1;i++)L[i] = A[left + i];
  for(i=0;i<=n2-1;i++)R[i] = A[mid + i];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  int j = 0;
  for(int k=left;k<=right-1;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
    count++;
  }
}

void mergeSort(int *A, int left, int right){
   if(left+1 < right){
     int mid = (left + right)/2;
     mergeSort(A, left, mid);
     mergeSort(A, mid, right);
     merge(A, left, mid, right);
   }
 }

int main(){
  
  scanf("%d", &n);  
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  mergeSort(A,0,n);
  printf("%d",A[0]);
  for(i=1;i<n;i++)printf(" %d",A[i]);
  printf("\n%d\n",count);

  return 0;
}

  

