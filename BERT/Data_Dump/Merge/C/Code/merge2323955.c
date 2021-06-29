#include<stdio.h>
#define INFTY 1000000000
int n,S[500000],count=0;
void merge(int S[], int left, int mid, int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1], R[n2];
    for(i = 0;i<n1;i++){
      L[i] = S[left + i];
    }
  for(i = 0; i<n2;i++){
    R[i] = S[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k<right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
      count++;
    }
    else{ 
      S[k] = R[j];
      j = j + 1;
      count++;
    }
  }
}
int mergeSort(int S[], int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
