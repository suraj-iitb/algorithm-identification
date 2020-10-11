//2019.12.22
//s1270188 xxxmk2
//alds1_06a

#include<stdio.h>
#include<stdlib.h>

#define N 10001

int main(){
  int *A, *B, C[N], num;
  int i;
  
  //clear CNT
  for(i=0;i<N;i++) C[i]=0;

  //input
  scanf("%d",&num);
  A=(int *)malloc(sizeof(int)*num);
  B=(int *)malloc(sizeof(int)*num);
  for(i=0;i<num;i++) {
    scanf("%d",&A[i]);
    C[A[i]]++;
  }

  //C
  for(i=1;i<N;i++) C[i]+=C[i-1];

  //B
  for(i=num-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
  }


  //output
  for(i=0;i<num-1;i++) printf("%d ",B[i]);
  printf("%d\n",B[i]);
  
  free(A);
  free(B);
  return 0;
}


