#include<stdio.h>

#define N 100
 
int main(){
  int i, j, count, A[N], key;
  scanf("%d", &count);

  for(i = 0; i < count; i++){
    scanf("%d",&A[i]);
  }

  for(j = 0; j < count-1; j++){
      printf("%d ",A[j]);
    }

    printf("%d\n", A[count-1]);

  for(i = 1; i < count; i++){
    key = A[i];
    j = i-1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }

    for(j = 0; j < count-1; j++){
      printf("%d ",A[j]);
    }
    printf("%d\n", A[count-1]);
  }
  return 0;
}
