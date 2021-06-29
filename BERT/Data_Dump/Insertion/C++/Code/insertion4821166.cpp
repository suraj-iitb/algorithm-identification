#include <stdio.h>

void trance(int A[], int N){
 for(int i = 0; i < N; i++){
  printf("%d", A[i]);
  if(i != N -1){
      printf(" ");
  }
 }
 printf("\n");
}

void insertionSort(int A[], int N){
 int temp;
 for(int i = 0; i < N; i++){
  temp = A[i];
  int j = i - 1;
  while(j>=0 && A[j] > temp){
   A[j+1] = A[j];
   j--;
  }
  A[j+1] = temp;
  trance(A, N);
 }
}

int main(){
 int A[100], N;
 scanf("%d", &N);
 for(int i = 0; i < N; i++){
  scanf("%d", &A[i]);
 }
 insertionSort(A, N);
 return 0;
}
