#include<stdio.h>
#define N 2000001

int *A,*B;

void CountingSort(int);


main(){
  int i,k;
  scanf("%d",&k);
  A = malloc(sizeof(int)*k+1);
  B = malloc(sizeof(int)*k+1);

  for(i=0; k>i; i++){
    scanf("%d",&A[i]);
  }

  CountingSort(k);
 for(i=1; i<=k; i++){printf("%d",B[i]);
    if(i<k)printf(" ");
  }
printf("\n");
 return 0;
}

void CountingSort(int k){

  int i, C[N];

  for(i=0; i<k; i++){
    C[i] = 0;
  }

  for(i=0; i<k; i++){
    C[A[i]]++;

  }


  for(i=0; i<N; i++){

    C[i] = C[i]+C[i-1];

    if(C[i] == k) break;
  }

  for(i=k-1; i>=0; i--){

    B[C[A[i]]] = A[i];
C[A[i]]--;
}
}
