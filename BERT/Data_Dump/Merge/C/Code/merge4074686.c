#include<stdio.h>


void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int cnt=0;

int main(){
  
  int innum,i;
  
  scanf("%d",&innum);
  
  int array[innum];
  
  for(i=0;i<innum;i++){
    scanf("%d",&array[i]);
  }
  
  
  
  mergeSort(array,0,innum);
  
  
  
  for(i=0;i<innum;i++){
    if(i==innum-1)printf("%d\n",array[i]);
    else printf("%d ",array[i]);
    
  }  
  printf("%d\n",cnt);
  
  return 0;
}


void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;
  int L[n1],R[n2];
  
  for (i = 0 ;i<=n1-1;i++)
    L[i] = A[left + i];
  for (i = 0;i<=n2-1;i++)
    R[i] = A[mid + i];
  
  L[n1] = 999999999;
  R[n2] = 999999999;
  
  i = 0;
  j = 0;
  for(k = left;k<=right-1;k++){
    cnt++;
    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
	}
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}
void mergeSort(int A[],int left,int right){
  int mid;
  
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  
}

