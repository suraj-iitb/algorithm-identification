#include<stdio.h>
#include<math.h>
int count=0;
void merge(int *A,int left,int mid,int right){
  int n1 = mid-left;
  int n2 = right-mid;
  int L[n1+1], R[n2+1],i,j,k;
  for (i=0;i<n1;i++){
    L[i]=A[left+i];
  } 
  for (i=0;i<n2;i++){
    R [i]=A[mid+i];
  }
  L[n1] = 1000000001;
  R[n2] = 1000000001;
  i = 0;
  j = 0;
  for (k=left;k<right;k++){
      if (L[i]<=R[j]){
	count++;
	A[k]=L[i];
	i=i+1;
      }
      else{
	A[k]=R[j];
	count++;
	j=j+1;
      }
  }
}
void mergeSort(int *A,int left,int right) {
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main(){
  int n,right,left=0;
  int A[500000];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  right=n;
  mergeSort(A,left,right);
  printf("%d",A[0]);
  for(i=1;i<n;i++){
    printf(" %d",A[i]);
    }
  printf("\n%d\n",count);    
  return 0; 
}

