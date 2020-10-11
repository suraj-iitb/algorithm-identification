#include <stdio.h>
#define INFTY 10000000000
int n;
long long int L[500000];
long long int R[500000];
long long int S[500000];
long long int count=0;
void merge(long long int *A,int l,int m,int r){
  int n1=m-l;
  int n2=r-m;
  int i,j,k;
  int t;
  for(i=0;i<n1;i++)L[i]=A[l+i];
  for(i=0;i<n2;i++)R[i]=A[m+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=l;k<r;k++){
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
}
void mergesort(long long int *A,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m,r);
    merge(A,l,m,r);
  }
}
int main(){
  int i;
  scanf("%lld",&n);
  for(i=0;i<n;i++)scanf("%lld",&S[i]);
  mergesort(S,0,n);
  for(i=0;i<n-1;i++)printf("%lld ",S[i]);
  printf("%lld\n",S[i]);
  printf("%lld\n",count);
  return 0;
}
