#include<stdio.h>
#define N 100

main(){
  int i, j, c, A[N], key;
  scanf("%d",&c);
  for(i = 0;i < c;i++){
    scanf("%d",&A[i]);
  }
  for(j = 0;j < c - 1;j++){
      printf("%d ",A[j]);
    }
    printf("%d\n", A[c-1]);
  for(i = 1;i < c;i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
    for(j = 0;j < c - 1;j++){
      printf("%d ",A[j]);
    }
    printf("%d\n", A[c-1]);
  }
  return 0;
}
