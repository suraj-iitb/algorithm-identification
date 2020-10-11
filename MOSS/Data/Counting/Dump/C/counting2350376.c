#include<stdio.h>
#include<stdlib.h>
 
#define N 2000000
#define MAX 10000
 
int main(){
  int k,i,j,C[MAX+1];
  unsigned short  *A,*B;
   
  scanf("%d",&k);
 
  A = malloc(sizeof(short)*k+1);
  B = malloc(sizeof(short)*k+1);
 
  for(i = 0; i <= MAX; i++){
    C[i] = 0;
  }
 
  for(i = 1; i <= k; i++){
    scanf("%d",&A[i]);
    C[A[i]]++;
  }
   
   
  for(i = 1; i <= MAX; i++){
    C[i] += C[i-1];
  }
 
  for(j = k; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i = 1; i <= k; i++){
    if(i > 1) printf(" ");
    printf("%d",B[i]);
  }
 
  printf("\n");
 
  return 0;
}
