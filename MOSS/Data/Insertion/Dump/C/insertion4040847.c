#include <stdio.h>
void output(int A[], int Max); //出力をする関数
void insertionSort(int A[], int Max); //並べ直す関数
int main(){

  int i , N , A[100];

  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  insertionSort(A , N);

  return 0;
}

void output(int A[] , int Max){
  int i;

  for(i = 0; i < Max; i++){
    if(i>0 && i<Max) printf(" ");
    printf("%d",A[i]);
  }
}

void insertionSort(int A[] , int Max){
  int i, v, j;

  for(i = 0; i < Max; i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j + 1] = v;
    output(A , Max);
    printf("\n");
  }
}
