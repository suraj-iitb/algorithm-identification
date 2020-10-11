#include<stdio.h>
#include<stdlib.h>
#define M 2000001
#define AM 10000

int main(){
  unsigned short *A,*B;
  int in[AM+1];
  int lo,i,s;
  
  scanf("%d",&lo);

  A=malloc(sizeof(short)*lo+1);

  B=malloc(sizeof(short)*lo+1);

  for(i=0;i<=AM;i++){
    in[i]=0;
      }

  for(i=0;i<lo;i++){
    scanf("%hu",&A[i+1]);
    in[A[i+1]]++;
  }

  for(i=1;i<=AM;i++){
    in[i]=in[i]+in[i-1];
  }

  for(i=lo;i>=1;i--){
    B[in[A[i]]]=A[i];
    in[A[i]]--;
  }

  for(i=1;i<=lo;i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");


  return 0;
}
    
  

