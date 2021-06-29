#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000
#define MAX2 10000

main(){
  unsigned short *A, *B;

  int BOX[MAX2+1];
  int n, i, j;
  scanf("%d", &n);

   A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<=MAX2;i++){
    BOX[i]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    BOX[A[i+1]]++;
  }

  for(i=1;i<=MAX2;i++){
    BOX[i]=BOX[i]+BOX[i-1];
  }
  
  for(j=1;j<=n;j++){
    B[BOX[A[j]]]=A[j];
    BOX[A[j]]--;
  }

  for (i=1;i<=n;i++){
    if (i>1)printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
  return 0;
}

