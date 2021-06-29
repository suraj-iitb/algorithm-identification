#include<stdio.h>

#define MAX 500000
#define SENTINEL 2000000000
int L[MAX/2+2];
int R[MAX/2+2];
int count;
void merge(int A[],int n,int left,int mid,int right);
void mergesort(int A[],int n,int left,int right);

int main(){
  int A[MAX];
  int N,i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  mergesort(A,N,0,N);
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");    
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
  
}
void merge(int A[],int n,int left,int mid,int right){
  int i,j,k;
  int n1;
  int n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0,j=0;
  for(k=left;k<right;k++){
      count++;
      if(L[i]<=R[j]){

	A[k]=L[i];
	i++;
      }
      else{
	A[k]=R[j];
	j++;
      }
    }
  }

void mergesort(int A[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}
  

