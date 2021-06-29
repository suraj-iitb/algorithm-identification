#include<stdio.h>
#define N 500000
#define INF 2000000000
int count;
void merge(int S[],int n,int left,int mid,int right);
void mergeSort(int S[],int n,int left,int right);
int L[N],R[N];
int main(){
  int i,n;
  int S[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  count = 0;
  mergeSort(S,n,0,n);
  for(i=0;i<n;i++){
    if( i>0 ) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
void merge(int S[],int n,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++){
    L[i] = S[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = S[mid+i];
  }
  L[n1] = INF;
  R[n2] = INF;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    count++;
    if( L[i] <= R[j] ){
      S[k] = L[i];
      i++;
    }
    else{
      S[k] = R[j];
      j++;
    }
  }
}
void mergeSort(int S[],int n,int left,int right){
  int mid;
  if( left+1 < right ){
    mid = ( left+right ) / 2;
    mergeSort(S,n,left,mid);
    mergeSort(S,n,mid,right);
    merge(S,n,left,mid,right);
  }
}
