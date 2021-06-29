#include<stdio.h>
#include <stdlib.h>

int main(){
  int n,C[2000001];
  int i,j;
  unsigned short *A, *B;
  
  scanf("%d",&n);
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<=10000;i++){
    C[i]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }
  
  for(i=1;i<=10000;i++){
    C[i]+=C[i-1];
  }

  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i>1){
      printf(" ");
    }
    printf("%d",B[i]);
  }
  printf("\n");
  
  return 0;
}
    

