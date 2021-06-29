#include <stdio.h>
#define DEKAI 1000000000
#define N 500000
void merge(int[],int,int,int);
void mergeSort(int[],int,int);
int count=0;
int L[N/2 +2],R[N/2+2];
int main(){
  int A[N],i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
   }
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}


void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
  
}
void merge(int A[],int left,int mid,int right){
int k,i,j;

  int n1=mid-left;
  int n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid +i];
  }
  L[n1]=R[n2]=DEKAI;
  i=0,j=0;
  for(k=left;k<right;k++){
count++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }
    else{
      A[k]=R[j++];
    }
  }
  
}

