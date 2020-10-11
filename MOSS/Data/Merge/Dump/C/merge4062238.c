#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 500000



int merge(int *A,int l,int r,int m){
  
  int cnt=0,i,j,k,n1,n2;
  n1=m-l;
  n2=r-m;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++) L[i]=A[l+i];
  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1]=(int)INFINITY;
  R[n2]=(int)INFINITY;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i]<=R[j])  A[k]=L[i++];
    else            A[k]=R[j++];
    cnt++;
  }
  return cnt;
}

int mergeSort(int *A,int l,int r){
  int m,cnt=0;
  if(l+1<r){
    m=(l+r)/2;
    cnt+=mergeSort(A,l,m);
    cnt+=mergeSort(A,m,r);
    cnt+=merge(A,l,r,m);
  }
  return cnt;
}

int main(){

  int cnt,n,i,r,l;
  int S[N];

  scanf("%d",&n);

  l=0;
  r=n;
  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  cnt=mergeSort(S,l,r);

  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",cnt);
  
  return 0;
}

