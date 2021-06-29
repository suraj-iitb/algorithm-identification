#include<stdio.h>

#define MAX 1000000
#define INFTY 2000000000

int count=0;

void merge(int[],int,int,int);
void mergesort(int[],int,int);

int main(){

  int i,n;
  int arr[MAX];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  mergesort(arr,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",arr[i]);
  }
  printf("%d\n",arr[i]);
  printf("%d\n",count);

 
  return 0;
}


void mergesort(int A[],int left,int right){
  
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void merge(int A[],int left,int mid,int right){
  
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;
  
  int arr2[n1+1],arr3[n2+1];

  for(i=0;i<=n1-1;i++){
    arr2[i] = A[left+i]; 
  }

  for(i=0;i<=n2-1;i++){
    arr3[i] = A[mid+i];
  }
  
  arr2[n1] = INFTY;
  arr3[n2] = INFTY;
   
  i=0;
  j=0;

  for(k=left;k<=right-1;k++){
    count++;
    if(arr2[i]<=arr3[j]){
      A[k] = arr2[i];
      i++;
    }
    else{
      A[k] = arr3[j];
      j++;
    }
  }
  
}
