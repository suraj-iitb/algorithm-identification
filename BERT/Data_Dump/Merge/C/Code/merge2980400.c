#include <stdio.h>
#include <math.h>

void merge(int,int,int);
void mergeSort(int,int);

int S[500000],mar=0;
int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  mergeSort(0,i);
  for(i=0;i<n;i++){
    if(i!=n-1)printf("%d ",S[i]);
    else printf("%d",S[i]);
  }
  printf("\n%d\n",mar);
  
  
  return 0;
}

void merge(int left,int mid,int right){
  int i=0,j=0,k,n1,n2,L[mid-left+1],R[right-mid+1];
  n1 = mid-left;
  n2 = right-mid;
  for(i=0;i<n1;i++)L[i] = S[left + i];
  for(i=0;i<n2;i++)R[i] = S[mid + i];
  L[n1] = 2000000000;
  R[n2] = 2000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    mar++;
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
    }
    else {
      S[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

