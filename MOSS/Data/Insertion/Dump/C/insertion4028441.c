#include <stdio.h>

#define N 1000

int main(){
  int i, j, k, v, a_length;
  int A[N];

  scanf("%d", &a_length);

  for(i = 0; i < a_length; i++){
    scanf("%d", &A[i]);
  }

  for(i = 1; i <= a_length; i++){
    v = A[i];
    j = i - 1;
    for(k = 0; k < a_length - 1; k++)
      {
        printf("%d ", A[k]);
      }
    printf("%d", A[k]);
    printf("\n");
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
  }
  
  return 0;
}

