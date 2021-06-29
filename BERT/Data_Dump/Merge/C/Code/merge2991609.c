#include <stdio.h>
#define N 500000
#define INFTY 1000000000
int A[N],cnt=0;
void merge(int,int,int);
void mergeSort(int,int);
int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
   printf("%d\n",A[n-1]);
   printf("%d\n",cnt);
  return 0;
}
void merge(int left,int mid,int right){
  int i,j,k;
  int n1 = mid-left;
  int n2 = right-mid;
  int L[n1+1], R[n2+1];
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
     cnt++;
    if (L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else {
      A[k]=R[j];
      j=j+1;
    }
  }
}
void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
   
    mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
      }

}
					 

