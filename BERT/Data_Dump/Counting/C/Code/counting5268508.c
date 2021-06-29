#include<stdio.h>
#include<stdlib.h>
#define N 2000001


int main(){


  int i,j;
  int n;
  int *A,*B,*C;

  A=(int *)malloc(sizeof(int )*N);
  B=(int *)malloc(sizeof(int )*N);
  C=(int *)malloc(sizeof(int )*100001);
  for(i=0;i<100001;i++)C[i]=0;




  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    C[A[i]]++;
  }

  for(i=1;i<100001;i++){
    C[i]=C[i-1]+C[i];
  }


  for(i=1;i<=n;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }



  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

















  return 0;
}

