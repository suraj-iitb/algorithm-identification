#include <stdio.h>
#define INFTY 1000000001
void merge(int [],int,int,int);
void mergeSort(int [],int,int);
int count=0;
int main(){

  int i,n,A[500000];

  int left,right;


  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){

    scanf("%d",&A[i]);

  }
  left=0;
  right=n;
  mergeSort(A,left,right);


  for(i=0;i<n-1;i++){
      printf("%d ",A[i]);
    
  }
  printf("%d\n%d\n",A[n-1],count);

  return 0;

}

void merge(int A[],int left,int mid,int right){


  int n1,n2;

 int j=0;
    int i;
  n1=mid-left;
  n2=right-mid;

  int L[n1],R[n2];

  for(i=0;i<=n1-1;i++){

    L[i]=A[left+i];

  }
  
  for(i=0;i<=n2-1;i++){

    R[i]=A[mid+i];

  }
  
    L[n1]=INFTY;
    R[n2]=INFTY;
     i=0;
     j=0;
    for(int k=left;k<=right-1;k++){

      if(L[i]<=R[j]){
	A[k]=L[i];
	i=i+1;
	count++;
      }
      else{

	A[k]=R[j];
	j=j+1;
	count++;
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

