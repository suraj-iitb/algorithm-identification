#include <stdio.h>
#define MAX 500000
#define INFTY 1000000000

void mergeSort(int A[],int,int);
void merge(int A[],int,int,int);
int left,right,A[MAX],n,count=0;

int main(){
  int i,j;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  left = 0;
  right = n;

  mergeSort(A,left,right);

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);


  return 0;
}


void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;
  
  int L[n1],R[n2];
 for(i=0;i<n1;i++){
   L[i] = A[left+i];
 }
 for(j=0;j<n2;j++){
   R[j] = A[mid+j];
 }
 
 L[n1] = INFTY;
 R[n2] = INFTY;
 i = 0;
 j = 0;
 
 for (k=left;k<right;k++){
   count++;
   
   if (L[i] <= R[j]){
    A[k] = L[i];
    i++;
   }
   else{
     A[k] = R[j];
     j++;
   }
   
 }
 
}

