#include "stdio.h"

void merge(int matrix[], int left, int mid, int right, int* pcnt){

  int n1 = mid - left;
  int n2 = right - mid;

  int* Left  = new int [n1+1];
  int* Right = new int [n2+1];

  for(int i=0;i<n1;i++){
    Left[i] = matrix[left+i];
  }

  for(int i=0;i<n2;i++){
    Right[i] = matrix[mid+i];
  }
  
  int max = 2000000000;
  Left[n1] = max;
  Right[n2] = max;

  int j,k;
  j=0;
  k=0;
  for(int i=left;i<right;i++){
    *pcnt =  *pcnt + 1;
    if(Left[j] <= Right[k] ){
      matrix[i] = Left[j];
      j++;
    }else{
      matrix[i] = Right[k];
      k++;
    }
  }
 
  delete [] Left;
  delete [] Right;

}

void mergeSort(int matrix[], int left, int right, int* pcnt){

  int mid = (int)( ( left+right)/2.0 );
  
  if(left + 1 >= right){
    return;
  }else{
    mergeSort(matrix, left, mid, pcnt);
    mergeSort(matrix, mid, right, pcnt);
    merge(matrix, left, mid, right, pcnt);
  }

}


void outputMatrix(int matrix[], int N){
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d", matrix[i]);
  }
  printf("\n");
}

int main(void){
  
  int N;
  scanf("%d", &N);

  int* matrix = new int [N];
  for(int i=0;i<N;i++){
    scanf("%d", &matrix[i]);
  }
  
  int cnt = 0;
  mergeSort(matrix, 0, N, &cnt);
  outputMatrix(matrix, N);
  printf("%d\n", cnt);

  delete [] matrix;

  return 0;
}
