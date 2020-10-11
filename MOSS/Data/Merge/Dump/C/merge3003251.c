#include<stdio.h>
void margesort(int *,int,int);
void marge(int *,int,int,int);
int count=0,A[100000000],L[50000001],R[50000001];
int main(){
  int n,i;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

margesort(A,0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
  }

void margesort(int *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    margesort(A,left,mid);
    margesort(A,mid,right);
    marge(A,left,mid,right);
  }
}

void marge(int *A,int left,int mid,int right){
  int n1,n2,i,j=0,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  L[n1]=1000000000;
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  R[n2]=10000000000;
  i=0;
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
}

