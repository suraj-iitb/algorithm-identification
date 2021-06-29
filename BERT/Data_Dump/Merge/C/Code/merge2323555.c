#include<stdio.h>
#define INFTY 1000000000
#define MAX 500000

int cnt=0,A[MAX];

void merge(int A[], int left, int mid, int right){
  int n1,n2,i,j,k;
  int L[MAX],R[MAX];
  n1 = mid - left;
  n2 = right - mid;
  
    
   for(i = 0;i<n1;i++){
     L[i] = A[left + i];
   }
 for(i = 0;i<n2;i++){
   R[i] = A[mid + i];
 }
 L[n1] = INFTY;
 R[n2] = INFTY;
    i = 0;
    j = 0;
    for(k = left;k<right;k++){
      cnt++;
      if(L[i] <= R[j]){
	A[k] = L[i];
	i++;
      }
      else {
	A[k] = R[j];
	j++;
	}
    }
}

void mergeSort(int A[], int left, int right){
  int mid =0;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
      }
}
int main(){

  int i,n;
 
  scanf("%d",&n);

  for(i=0;i<n;i++){
      scanf("%d",&A[i]);
  }
  
  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i != n-1) printf(" ");
  }
 
  printf("\n"); 
  printf("%d\n",cnt);
  
  return 0;
  
}

  
  
