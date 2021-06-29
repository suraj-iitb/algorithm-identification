#include<stdio.h>
#include<stdlib.h>
#define SENTINEL 1000000000

int c=0;
void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  int *L,*R;
  n1=mid-left;
  n2=right-mid;
  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));
  for(i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=A[mid+j];
  }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
   if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      c++;
    }
    else{
      A[k]=R[j];
      j++;
      c++;
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
  int i,num;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,num);
  for(i=0;i<num;i++){
    printf("%d",A[i]);
    if(i<num-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

