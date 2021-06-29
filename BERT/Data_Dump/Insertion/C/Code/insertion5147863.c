#include<stdio.h>
#define MAX 1000
int main(){
  int i, j, x, A[MAX], v;

  scanf("%d", &x);
  for(i = 0; i < x; i++){
    scanf("%d", &A[i]);
  }
  printf("%d", A[0]);
  for(i = 1; i < x; i++){
    printf(" %d", A[i]);
  }
  printf("\n");
  for(i = 1; i < x; i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    printf("%d", A[0]);
    for(j = 1; j < x; j++){
      printf(" %d", A[j]);
    }
    printf("\n");
  }
  return 0;
}



