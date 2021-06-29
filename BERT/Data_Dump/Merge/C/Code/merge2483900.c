#include <stdio.h>

#define M 500000
#define S 2000000000

int L[M/2+2],R[M/2+2];
int cou=0;

void mer(int *A,int n,int left,int right,int mid){
  int i=0,j=0,k,na,nb;

  na=mid-left;
  nb=right-mid;

  for(i=0;i<na;i++) L[i]=A[left+i];
  for(i=0;i<nb;i++) R[i]=A[mid+i];

  L[na]=R[nb]=S;
  i=j=0;

  for(k=left;k<right;k++){
    cou++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }else {
      A[k]=R[j++];
    }
  }
}

void mers(int *A,int n,int left,int right){
  int mid;
  
  if(left+1<right){
    mid=(left+right)/2;
    mers(A,n,left,mid);
    mers(A,n,mid,right);
    mer(A,n,left,right,mid);
  }
}

int main(){
  int i,A[M],n;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mers(A,n,0,n);

  for(i=0;i<n;i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  printf("%d\n",cou);

  return 0;
}
    
