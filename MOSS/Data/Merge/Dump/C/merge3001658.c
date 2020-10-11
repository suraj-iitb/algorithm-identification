#include<stdio.h>
#include<stdlib.h>
#define SENTINEL 1000000000

int count=0;

void merge(int A[],int left,int mid,int right){
  int a,b,i,j,k;
  int *L,*R;
  a=mid-left;
  b=right-mid;
  L=(int *)malloc(sizeof(int)*(a+1));
  R=(int *)malloc(sizeof(int)*(b+1));

  for(i=0;i<=a-1;i++){
    L[i]=A[left+i];
  }

  for(j=0;j<=b-1;j++){
    R[j]=A[mid+j];
  }

  L[a]=SENTINEL;
  R[b]=SENTINEL;
  i=0;
  j=0;

  for(k=left;k<=right-1;k++){
   if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }

  free(L);
  free(R);
}

void mergeSort(int A[],int left,int right){
  int i,mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int A[500000];
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  
  printf("\n");
  printf("%d\n",count);
  return 0;
}
