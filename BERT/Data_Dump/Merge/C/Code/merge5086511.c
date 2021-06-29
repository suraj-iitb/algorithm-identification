#include <stdio.h>
#define INF 1000000001

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int C;

int main(){
  int n,q,g,i;
  scanf("%d",&n);

  int B[n];
  for(i=0;i<n;i++){
    scanf("%d",&B[i]);
  }

  while(1){
    if(i=n) break;
  }  
    mergesort(B,0,n);
    for(i=0;i<n-1;i++){
      printf("%d ",B[i]);
    }
    printf("%d\n%d\n",B[n-1],C);

    return 0;
}

void mergesort(int *A,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m,r);
    merge(A,l,m,r);
  }
}  



void merge(int *A,int L,int m,int R){
  int n1,n2,i,j,k;

  n2=R-m;
  n1=m-L;

  int I[n1+1],r[n2+1];

  for(i=0;i<n1;i++){
    I[i]=A[L+i];
  }
  for(i=0;i<n2;i++){
    r[i]=A[m+i];
  }
  I[n1]=INF;
  r[n2]=INF;

  j=0;
  i=0;

  for(k=L;k<R;k++){
    if(I[i]<=r[j]){
      A[k]=I[i];
      i=i+1;
    }
    else{
      A[k]=r[j];
      j=j+1;
    }
    C++;
  }}
