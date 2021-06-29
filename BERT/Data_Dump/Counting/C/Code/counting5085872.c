#include<stdio.h>
#include<stdlib.h>
#define M 2000001
#define V 10000
int main(){
  unsigned short *A,*B;
  int d,i;
  int C[V+1];
  scanf("%d",&d);
  A=malloc(sizeof(short)*d+1);
  B=malloc(sizeof(short)*d+1);
  for(i=0;i<10000;i++) C[i]=0;
  for(i=0;i<d;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }
  for(i=1;i<=V;i++)C[i]=C[i]+C[i-1];
  for(i=1;i<=d;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<=d;i++){
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}

