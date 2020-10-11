#include <stdio.h>
#define N 500000
#define M 2147483647
void marge(int *,int,int,int);
void margeSort(int *,int,int);
int count=0,n,i,S[N];
int main(){
 

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  margeSort(S,0,n);

  for(i=0;i<n-1;i++)
    printf("%d ",S[i]);
  printf("%d\n%d\n",S[n-1],count);
  
  
  return 0;
}

void marge(int *A,int left,int mid,int right){
  int n1,n2,j,k;
  int L[N/2+1],R[N/2+1];
  n1=mid-left;
  n2=right-mid;



  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=M;
  R[n2]=M;

  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      count++;
    }
    else {
      A[k]=R[j];
      j=j+1;
      count++;
    }
  }
  
}

void margeSort(int *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    margeSort(A,left,mid);
    margeSort(A,mid,right);
    marge(A,left,mid,right);
  }
  
}
