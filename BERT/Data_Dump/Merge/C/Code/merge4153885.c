#include<stdio.h>
#define MAX 500000
#define mugen 2000000000

int S[MAX],L[MAX/2+2],R[MAX/2+2],count;

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main(){
  int n,i;
  count = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  
  mergeSort(S,0,n);
  
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

void merge(int *S,int left,int mid,int right){
  int i,j,k;
  int l,r;

  l=mid-left;
  r=right-mid;

  for(i=0;i<l;i++) L[i]=S[left+i];
  for(i=0;i<r;i++) R[i]=S[mid+i];

  L[l]=mugen;
  R[r]=mugen;

  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]) S[k]=L[i++];
    else S[k]=R[j++];
  }
}

void mergeSort(int *S,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}

