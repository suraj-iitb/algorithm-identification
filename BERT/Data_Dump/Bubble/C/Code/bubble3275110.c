#include<stdio.h>
#include<stdbool.h> //ブーリアン型(Boolean datatype)で、真理値の２つの値をとる
#define SWAP(type,a,b) {type temp = a; a = b; b = temp;}  //SWAPとは、2つの変数の値を交換するマクロや関数

static const int N = 100;

int bubbleSort(int A[], int n){
  int count = 0;
  int i, j;
  bool flag = 1;
  for(i = 0; flag ; i++){
    flag = 0;
    for(j = n -1; j >= i + 1; j--){
      if(A[j] < A[j-1]){
        SWAP(int,A[j], A[j-1] );
        flag = 1;
        count++;
      }
    }
  }
  return count;
}

int main(){
  int A[N+1], n, i, count;
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  count = bubbleSort(A, n);
  for(i = 0; i < n ; i++){
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d", count);
  printf("\n");
  return 0;
}

