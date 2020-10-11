#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

int n;
void CountingSort(unsigned short *A,unsigned short *B){
  int i,j,C[VMAX+1];

  for(i=0;i<=VMAX;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=VMAX;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

int main(){
  int i;
  unsigned short *A,*B;

  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
  }

  CountingSort(A,B);

  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

