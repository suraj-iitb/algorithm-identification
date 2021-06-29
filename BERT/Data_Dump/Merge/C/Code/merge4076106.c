#include<stdio.h>

#define INFTY 1000000000;

int A[500000];

int marge(int left,int mid,int right){
  int i,j,k;
  static int count=0;
  int n1=mid-left;
  int n2=right-mid;
  int L[250001];
  int R[250001];
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    count++;
  }
  return count;
}


int margesort(int left,int right){
  int a;
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    margesort(left,mid);
    margesort(mid,right);
    a=marge(left,mid,right);
  }
  return a;
}

int main(){
  int i,count,N;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  count=margesort(0,N);
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

