#include<stdio.h>
#define N 500000

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int count = 0;

int main(){
  int i,n;
  int S[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  mergesort(S,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[i]);
  printf("%d\n",count);

  return 0;
}
void mergesort(int *S,int left,int right){
  int mid;

  if(left+1<right){
    mid = (left+right)/2;
    mergesort(S,left,mid);
    mergesort(S,mid,right);
    merge(S,left,mid,right);
  }
}
void  merge(int *S,int left,int mid,int right){
  int n1,n2;
  n1 = mid - left;
  n2 = right - mid;
  int i,j,k;
  int L[N];
  int R[N];

  for(i=0;i<n1;i++){
    L[i] = S[left+i];
  }

  for(j=0;j<n2;j++){
    R[j] = S[mid+j];
  }

  L[n1] = 999999999;
  R[n2] = 999999999;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i=i+1;
      count++;
    }
    else{
      S[k]=R[j];
      j=j+1;
      count++;
    }
  }
}

