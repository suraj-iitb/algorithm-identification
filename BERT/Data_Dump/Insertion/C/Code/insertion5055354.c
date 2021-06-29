#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
  int a, i, j, k, n, v;
  int A[N];

  scanf("%d", &n);
  if(n>100 || n<1) exit(1);

  for(k = 0; k < n; k++){
    scanf("%d", &A[k]);
    if(A[k]>1000 || A[k]<0) exit(2);
  }

  for(j = 1; j < n+1; j++){
    v = A[j];
    i = j-1;

    for(a=0; a<n; a++){
      if(a < n-1)  printf("%d ", A[a]);
      else  printf("%d", A[a]);
    }

    printf("\n");

    while(i >= 0 && A[i] > v){
      A[i+1] = A[i];
      i = i-1;
      }

    A[i+1] = v;

  }



  return 0;
}
