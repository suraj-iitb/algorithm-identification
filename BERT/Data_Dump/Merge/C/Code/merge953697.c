#include <stdio.h>

#define N 500000

void Merge(int A[],int l,int m,int r);
void MergeS(int A[],int l,int r);

int A[N],count=0;
main(){
  int n,i,m,l,r;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  MergeS(A,0,n);
  for(i = 0; i < n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}

void MergeS(int A[],int l,int r){
  int m;
  if(l + 1 < r){
    m = (l + r)/2;
    MergeS(A,l,m);
    MergeS(A,m,r);
    Merge(A,l,m,r);
  }
}
void Merge(int A[],int l,int m,int r){
  int n1=m-l,n2=r-m,i,j,k;
  int L[n1],R[n2];
  for(i = 0; i < n1; i++){
    L[i] = A[l+i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[m+i];
  }
  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  j = 0;
  for(k = l; k < r; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }else{
      A[k] = R[j];
      j++;
      count++;
    }
  }
}
