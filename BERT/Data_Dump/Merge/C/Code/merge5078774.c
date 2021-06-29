#include<stdio.h>

#define INF 2000000000
void  merge(int *,int ,int ,int );
void mergeSort(int *,int ,int );
int L[250002],R[250002];
int cnt=0;


int main(){
  int S[500000],n;
  int i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);
  //出力
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",cnt);
  //
  return 0;
}
void  merge(int *A,int left,int mid,int right){
  int n1=mid - left;
  int n2= right - mid;
  int i,j,k;

 
  // L[0...n1], R[0...n2] を生成
  for (i = 0;i<n1;i++){
    L[i] = A[left + i];
  }
  for (i = 0; i <n2 ;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;
  
  i = 0;
  j = 0;
  
  for (k = left; k < right;k++){
    cnt++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i ++;
    } else{ 
      A[k] = R[j];
      j ++;
    }
  }
}


void mergeSort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

