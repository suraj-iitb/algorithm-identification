#include<stdio.h>
#include<stdbool.h>

int main() {
  int i,j,N,v;
  int k=0,l=0;
  bool flg=true;
  int Min;
  int A[100];

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    /* code */
    scanf("%d", &A[i]);
  }
  if (flg==true) {


  for ( i = 0; i < N-1; i++) {
    /* code */
    Min=i;
    flg=false;
    for (j = i; j < N; j++) {
      /* code */
      if (A[j] < A[Min]){
        Min=j;
      }


    }
  if(A[i]!=A[Min]){
    v=A[i];
    A[i]=A[Min];
    A[Min]=v;
    k++;
    }

  }
}
  printf("%d", A[0]);

  for ( i = 1; i < N; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");
  printf("%d\n", k);
  return 0;
}

