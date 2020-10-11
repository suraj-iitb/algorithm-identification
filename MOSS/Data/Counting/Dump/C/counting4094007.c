#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
void CountingSort(short unsigned int *,short unsigned  int*, int);
int n;
int main(){
  unsigned short *A, *B;
  int  i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  for(i=1;i<=n;i++)
    scanf("%d",&A[i]);
  
  CountingSort(A,B,VMAX);
  
  free(A);
  free(B);
  return 0;
}

void CountingSort(short unsigned int *A,short unsigned int*B, int k){
  int C[VMAX+1],i,j;
  for(i=0;i<=k;i++)C[i]=0;

  for(j=1;j<=n;j++)C[A[j]]++;

  
  for(i=1;i<=k;i++)
    C[i]=C[i]+C[i-1];
  
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  
  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  


}

