#include<stdio.h>
#include<stdlib.h>

void merge(int *,int ,int,int);
void mergeSort(int *,int,int);

int num=0;

int main(){
  int *A;
  int n;
  int i;

  scanf("%d",&n);
  A=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  mergeSort(A,0,n);
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",num);
  
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2;
  int *L;
  int *R;
  int i,j,k;
  n1=mid-left;
  n2=right-mid;
  L=(int *)malloc((n1+1)*sizeof(int));
  R=(int *)malloc((n2+1)*sizeof(int));
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    num++;
  }
  free(L);
  free(R);
}
void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

