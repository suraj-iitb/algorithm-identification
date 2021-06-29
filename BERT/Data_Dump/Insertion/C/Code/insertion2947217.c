#include <stdio.h>

int main(){
  int i, j, s, t, N, A[1000];
  
  scanf("%d", &N );
  
  for(i=0; N>i; i++){
    scanf("%d", &A[i]);
  }

  for(i=1; N>i; i++){
    for(j=0; j<N-1; j++){
      printf("%d ", A[j]);
    }
    printf("%d\n", A[N-1] );
    s = A[i];
    t = i-1;
    while (t >=0 && s < A[t]) {
      A[t+1] = A[t];
      t--;
    }
    A[t+1] = s;
  }
  for(j=0; j<N-1; j++){
    printf("%d ", A[j]);
  }
  printf("%d\n", A[N-1]);
  return 0;
}

