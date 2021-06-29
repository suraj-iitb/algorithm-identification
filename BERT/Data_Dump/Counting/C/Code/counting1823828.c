#include <stdio.h>
#include <stdlib.h>

#define n 2000001
#define s 10000

int main(){
  int  *A,*B,C[s],a,i,j;

  scanf("%d",&a);

  A = malloc(sizeof(int) * a + 1);
  B = malloc(sizeof(int) * a + 1);

  for(i = 0; i < s; i++){
    C[i] = 0;
  }

  for(i = 0; i < a; i++) scanf("%d",&A[i]);
  
  for(i = 0; i < a; i++){
    C[A[i]]++;
  }

  for(i = 0; i < s-1; i++){
    C[i+1] += C[i];
  }

  for(i = a-1; i >= 0; i--){
    if(C[A[i]] == 0) continue;
    else {
      B[C[A[i]]-1] = A[i];
      C[A[i]]--;
    }
  }

  for(i = 0; i < a; i++){
    printf("%d",B[i]);
    if(a-1 != i) printf(" ");
  }
  printf("\n");

  return 0;
}
