#include<stdio.h>
#define MAX 500000

int i,j,k,count;
void Merge(int A[],int l,int m,int r);
void Merge_S(int A[],int l,int r);

int main(){
  int A[MAX],n;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  Merge_S(A,0,n);
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}

void Merge(int A[],int l,int m,int r){
  int n1=m-l,n2=r-m,L[n1], R[n2];
  for(i=0;i<n1;i++) L[i]=A[l+i];
  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1]=1000000000;
  R[n2]=1000000000;
  int i=0,j=0;
  for(k=l;k<r;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }
    else {
      A[k]=R[j];
      j++;
      count++;
    }
  }
}

void Merge_S(int A[],int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    Merge_S(A,l,m);
    Merge_S(A,m,r);
    Merge(A,l,m,r);
  }
}
