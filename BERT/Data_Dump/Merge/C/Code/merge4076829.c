#include<stdio.h>
#define INFINITY 1000000001

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int n;//データの個数を記録する
int count=0;
int S[500002];//配列の外部変数

int main (){
  int i;
  
  scanf("%d", &n);
  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &S[i]);
  }

  //printf("%d\n",S[0]);
  
  mergeSort( S, 0, i);

  for(i = 0;i < n; i++){
    printf("%d", S[i]);
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0;
}

void merge(int *A,int  left,int mid,int right){
  int i, j, k, n1, n2;
  int L[250001],R[250001];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0;i <= n1-1; i++){
    L[i] = A[left + i];//L[0...n1]を作成中なう
  }

  for(i = 0;i <= n2-1; i++){
    R[i] = A[mid + i];//R[0...n2]を作成中なう
  }

  L[n1] = INFINITY;
  R[n2] = INFINITY;

  i = 0;
  j = 0;

  for(k = left;k <= right-1; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }else{
      A[k] = R[j];
      j = j + 1;
    }
    count++;//比較回数を記録
  }
}

void mergeSort(int *A,int left,int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

