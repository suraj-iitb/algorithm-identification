#include<stdio.h>
#define INFINITY 1000000001
#define N 500000

int count=0;
void mergeSort(int *,int,int);
void merge(int *,int,int,int);

int main(){

  int n,k;
  int A[N];
  int left,right;

  scanf("%d",&n);

  left=0;
  right=n;

  for(k=0;k<n;k++){
    scanf("%d",&A[k]);
  }

  mergeSort(A,left,right);

  for(k=0;k<n;k++){
    printf("%d",A[k]);
    if(k==n-1) printf("\n");
    else printf(" ");
  }

  printf("%d\n",count);

  return 0;
  
}


void mergeSort(int *A,int left,int right){

  int mid;

  if(left+1 < right){

    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
    
  }
  
}

void merge(int *A,int left,int mid,int right){

  int n1,n2,i,j,k,lcount=0,rcount=0;
  int L[N],R[N];
  
  n1=mid-left;
  n2=right-mid;
  
  for(i=0;i<=n1-1;i++){
    L[i] = A[left+i];
    lcount++;
  }
 
  for(i=0;i<=n2-1;i++){
    R[i] = A[mid+i];
    rcount++;
  }
 

  L[n1]=INFINITY;
  R[n2]=INFINITY;

  i=0;
  j=0;
  
  for(k=left;k<=right-1;k++){

    if(L[i]<=R[j]){

      A[k]=L[i];
      lcount--;
      if(lcount>0){
	i++;
      }else{
	L[i]=INFINITY;
      }
      
    }else{

      A[k]=R[j];
      rcount--;
      if(rcount>0){
	j++;
      }else{
	R[j]=INFINITY;
      }
      
    }//if
    
    count++;
    
  }//for

}




