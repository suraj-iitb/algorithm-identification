#include <stdio.h>
#include <stdlib.h>
#define NMAX 2000000
#define AMAX 10000
int n=AMAX;
void CountingSort(unsigned short *,unsigned short *,int);
int main(){
  int i;
  unsigned short *A;
  unsigned short *B;
  int k;


  scanf("%d",&k);

  A=malloc(sizeof(short)*k+1);
  B=malloc(sizeof(short)*k+1);

  for(i=0;i<k;i++){
    scanf("%hu",&A[i+1]);
  }
  //  printf("ok1\n");
  CountingSort(A,B,k);
  return 0;
}

void CountingSort(unsigned short *A,unsigned short *B,int k){
  int i,j;
  int C[AMAX+1];
  //printf("ok2\n");
  for(i=0;i<=AMAX;i++){
    C[i]=0;
  }
  //printf("ok3\n");
  for(j=0;j<k;j++){
    C[A[j+1]]++;
  }
  //printf("ok4\n");
  for(i=1;i<=AMAX;i++){
    C[i]=C[i]+C[i-1];
  }
  //printf("ok5\n");
  for(j=1;j<=k;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  //printf("ok6\n");
  for(i=1;i<=k;i++){
    if(i>1)
      printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
}

