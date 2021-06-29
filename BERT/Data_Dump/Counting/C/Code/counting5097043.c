#include<stdio.h>

#define MAX 2000000
#define AMAX 10000

void countingsort(short *,short *,int);

int n;

int main(){
  int i, k;
  unsigned short A[MAX], B[MAX];

  scanf("%d",&n);

  for(i = 1 ; i <= n ; i++){
    scanf("%d",&A[i]);
  }

  k = A[1];
  for(i = 2 ; i <= n ; i++){
    if(k < A[i])k=A[i];
  }

  countingsort(A,B,k);

  for(i = 1 ; i <= n ; i++){
    if(i != 1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

void countingsort(short *A,short *B,int k){
  int i, C[AMAX] = {0};
  
  for(i = 1 ; i <= n ; i++){
    C[A[i]]++;
  }

  for(i = 1 ; i <= k ; i++){
    C[i] = C[i] + C[i - 1];
  }
  /*

  for(i = 1 ; i <= n ; i++){
    printf("%d",A[i]);
  }
  for(i = 0 ; i <= k ; i++){
    printf("%d",C[i]);
  }
  */
  for(i = n ; i >= 1 ; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

}

  

  

