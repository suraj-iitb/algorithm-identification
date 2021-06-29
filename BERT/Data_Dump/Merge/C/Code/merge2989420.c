#include<stdio.h>
#define INFTY 1000000000

int c=0;
int n1,n2;

void merge(int A[], int l, int m, int r){
  n1=m-l;
  n2=r-m;
  int L[n1], R[n2];
  int i=0, j=0, k=0;
  for(i=0;i<n1;i++)L[i]=A[l+i];
  for(i=0;i<n2;i++)R[i]=A[m+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      c++;
    }else{
      c++;
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergesort(int A[], int l, int r){
  if(l+1<r){
    int m;
    m = (l+r)/2;
    mergesort(A, l, m);
    mergesort(A, m, r);
    merge(A, l, m, r);
  }
}

int main(){
  int n,i;
  int A[500000];
  scanf("%d",&n);
   for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergesort(A,0,n);
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",A[i]);
      break;
    }
    printf("%d ",A[i]);
  }
  printf("%d\n",c);
  return 0;
}
