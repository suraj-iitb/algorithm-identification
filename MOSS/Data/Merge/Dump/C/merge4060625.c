#include <stdio.h>
#include <stdlib.h>
#define M 1000000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int count=0;
int left[M/2+2],right[M/2+2];

int main(){
  int i,n,arr[M];
  
  scanf("%d",&n);
  if(n>500000) exit(2);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  mergeSort(arr,0,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",arr[i]);
  }
  printf("\n%d\n",count);
  
  return 0;
}

void mergeSort(int arr[],int le,int ri){
  int mid;
  if(le+1<ri){
    mid = (le+ri)/2;
    mergeSort(arr,le,mid);
    mergeSort(arr,mid,ri);
    merge(arr,le,mid,ri);
  }
}

void merge(int arr[],int le,int mid,int ri){
  int i,j,k; 

  for(k=0;k<mid-le;k++){
    left[k]=arr[le+k];
  }
  for(k=0;k<ri-mid;k++){
    right[k]=arr[mid+k];
  }
  left[mid-le] = right[ri-mid] = 9999999999999;
  i=0;
  j=0;
  for(k=le;k<ri;k++){
  count++;
    if(left[i]<=right[j]){
      arr[k] = left[i];
      i++;
    }else{
      arr[k] = right[j];
      j++;
    }
  }
}

