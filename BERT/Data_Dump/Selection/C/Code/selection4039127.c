#include <stdio.h>

#define N 100

int main(){
  int i, j=0, k, inp, minj=0, temp, cha=0, count=0;
  int A[N];
  
  scanf("%d", &inp);
  for(i = 0; i < inp; i++) scanf("%d", &A[i]); /*set array*/
  
  for(j = 0; j < inp-1; j++){
    for(k = inp-1, minj = k; k > j; k--){
      if(A[minj] == A[k-1]){
        if(minj > k-1) minj = k-1;
      }
      if(A[minj] > A[k-1]) minj = k-1;
    }
    i = j; 
    if(A[minj] < A[i]){
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      count++;
    }
  }
  
  for(i=0; i < inp-1; i++) printf("%d ", A[i]);
  printf("%d", A[i]);
  printf("\n%d\n", count);
  return 0;
}

