#include<stdio.h>
#define n 500000
#define SENTINEL 2000000000
int count=0,A[n];


void marge(int left,int mid, int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  
  L[n1] =SENTINEL;
  R[n2] =SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k] = L[i];
      i=i+1;
      count++;
    }
    else {
      A[k]=R[j];
      j = j+1;
      count++;
    }
  }
}

void margesort(int left,int right){
  int mid;
  
  if(left+1<right){
    mid = (left + right)/2;
    margesort(left,mid);
    margesort(mid,right);
    marge(left,mid,right);
  }
}



int main(){
  int i,a,b,c,d;
  
  scanf("%d",&b);
  
  for(i=0;i<b;i++){
    scanf("%d",&A[i]);
  }
  
  margesort(0,b);
  
  for(i=0;i<b-1;i++){
    printf("%d",A[i]);
    printf(" ");
  }
  printf("%d\n",A[i]);
 
  printf("%d\n",count);
  return 0;
}
