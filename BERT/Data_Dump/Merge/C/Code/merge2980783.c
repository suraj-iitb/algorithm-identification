#include<stdio.h>
#include<stdlib.h>
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int cnt=0;
int main(){
  int l,m,r,n,i;
  int *A;
  scanf("%d",&n);
  A=(int *)malloc(n *sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  l=0;
  r=n;
  mergeSort(A,l,r);
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  free(A);
  return 0;
}
void merge(int A[],int l,int m,int r){
  int n1=m-l;
  int n2=r-m;
  int L[n1],R[n2];
  int i;
  for(i=0;i<n1;i++)L[i]=A[l+i];
  for(i=0;i<n2;i++)R[i]=A[m+i];
  L[n1]=2000000000;
  R[n2]=2000000000;
  i=0;
  int j=0;
  for(int k=l;k<r;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i+=1;
      cnt++;
    }
    else {
      A[k]=R[j];
      j+=1;
      cnt++;
    }
  }
}
void mergeSort(int A[],int l,int r){
  if(l+1<r){
    int m=(l+r)/2;
    mergeSort(A,l,m);
    mergeSort(A,m,r);
    merge(A,l,m,r);
  }
}

