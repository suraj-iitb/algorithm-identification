#include <stdio.h>
#include <stdlib.h>
#define K 10000

int main(){

  int i,j;
  int len,C[K+1];
  unsigned short *A,*B;

  scanf("%d",&len);
  A=malloc(sizeof(short)*len+1);
  B=malloc(sizeof(short)*len+1);

  for(i=0;i<=K;i++) C[i]=0;

  for(i=0;i<len;i++){
    scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
}

  for(i=0;i<=K;i++){
  C[i]+=C[i-1];
}

  for(j=1;j<=len;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=len-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);

  /*for ( i = 1; i <= len; i++ ){
  if ( i > 1 ) printf(" ");
  printf("%d", B[i]);
}
printf("\n");*/
  return 0;
}
