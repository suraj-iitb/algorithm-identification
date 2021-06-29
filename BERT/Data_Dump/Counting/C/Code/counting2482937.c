#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000
#define VMAX 10000
int main(){
  int n,i,j;
  short *A,*B;
  int C[VMAX+1];
  scanf("%d",&n);
  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);
  for (i = 0;i<=VMAX;i++)
    C[i] = 0;
  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
  }
  /* C[i] now contains the number of elements equal to i */
  for (i = 1;i<= VMAX;i++){
    C[i] = C[i]+C[i-1];
  }
  /* C[i] now contains the number of elements less than or equal to i */
  for (j = 1;j<=n;j++){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
  }
  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
  return 0;
}
