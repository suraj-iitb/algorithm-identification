#include <stdio.h>
#define N 500000
#define MAX 1000000000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int t=0;
int main(){
  int i,j,n,S[N];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i=0;i<n-1;i++)printf("%d ",S[i]);
  printf("%d\n%d\n",S[i],t);
  return 0;
}

void merge(int S[],int left,int mid,int right){
  int n1 = mid - left,n2 = right - mid;
  int L[n1],R[n2],i,j=0,k=0;
  for(i=0;i<n1;i++)L[i]=S[left+i];
  for(i=0;i<n2;i++)R[i]=S[mid+i];
  L[n1] = MAX;
  R[n2] = MAX;
  for(i=left;i<right;i++){
    if(L[j]<=R[k]){
      S[i]=L[j];
      j++;
      t++;
    }
    else{
      S[i]=R[k];
      k++;
      t++;
    }
  }
}

void mergeSort(int S[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S,left,mid,right);
  }
}
