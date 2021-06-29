#include<stdio.h>
#include<stdlib.h>

#define MAX 500001

void merge(int *,int,int,int);
void mergeSort(int *,int,int);
 
int count=0; 
 
int main(){
  int n,i;
  int S[MAX];
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    if(S[i]<0 || S[i]>1000000000){
      exit(1);
    }
  }
 
  mergeSort(S,0,n);
 
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);
  printf("%d\n",count);
 
  return 0;
}


void merge(int *A,int l,int m,int r){
  int n1=m-l;
  int n2=r-m;
  int i,j,k;
  int *L,*R;
 
  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));
 
  for(i=0;i<=n1-1;i++){
    L[i]=A[l+i];
  }
 
  for(j=0;j<=n2-1;j++){
    R[j]=A[m+j];
  }
 
  L[n1]=1000000000;
  R[n2]=1000000000;
 
  i=0;
  j=0;
 
  for(k=l;k<=r-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }else{
      A[k]=R[j];
      j=j+1;
    }
 
    count++;
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
