#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int *A, *C, key, bangou;
  int *B;
  int n, i, j;
  int count=0, max;

  scanf("%d", &n);
  if(n<1 || n>=MAX) exit(1);
  
  A = malloc(sizeof(int)*n);
  C = malloc(sizeof(int)*n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
    if(A[i]<0 || A[i]>VMAX) exit(2);
  }
  
  max = A[0];
  for(i=1; i<n; i++) if(max < A[i]) max = A[i];
  B = malloc( (max+2)*sizeof(int) );

  /*for(i=0; i<=max; i++){
    for(j=0; j<n; j++){
      if(A[j] == i) count++;
    }
    B[i] = count;
    }*/
  
  for(i=0; i<n; i++) B[A[i]]++;
  for(i=0; i<=max+1; i++) B[i] = B[i] + B[i-1];
  //for(i=0; i<=max+1; i++) printf("%-2d",B[i]);

  //for(i=0; i<=max; i++) printf("%d ",B[i]);
  //printf("\n");

  for(i=n-1; i>=0; i--){
    C[B[A[i]]-1] = A[i];
    B[A[i]]--;
  }

  //for(i=0; i<=max+1; i++) printf("%-2d", B[i]);
  
  for(i=0; i<n; i++){
    printf("%d",C[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");

  return 0;
}

