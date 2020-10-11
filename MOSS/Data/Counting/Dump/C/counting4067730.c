#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  // scanf("%d",&A[1]);
  //for(i=1;i<=n;i++){
    
    //  printf("%d %d %d\n",i,A[i],n);
  // }
  // for(i=1;i<=n;i++){
  // if(i-1)printf(" ");
  //  printf("%d",A[i]);
  // }
  // printf("\n");
  
  for(i=0;i<=VMAX;i++)C[i] = 0;

  for(j=1;j<=n;j++){
    scanf("%u",&A[j]);
    C[A[j]]++;
    
  }
 
  for(i=1;i<=VMAX;i++)C[i]+=C[i-1];
  //printf("aaaaaaaa\n");
  for(j=1;j<=n;j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
    // printf("aaaaaaaa\n");
    // printf("aaa:%d  ",A[j]);
  }
  //printf("B:");
  for(i=1;i<=n;i++){
    if(i-1)printf(" ");
    printf("%u",B[i]);
  }
  printf("\n");

  return 0;
}

