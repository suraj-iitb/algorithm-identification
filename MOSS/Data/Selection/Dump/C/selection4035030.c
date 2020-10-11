#include <stdio.h>

int main() {
  int i,j,N,v,k=0,l=0,flag=1;
  int minj;
  int A[100];

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    /* code */
    scanf("%d", &A[i]);
  }
  if (flag==1) {


  for ( i = 0; i < N-1; i++) {
    /* code */
    minj=i;
    flag=0;
    for (j = i; j < N; j++) {
      /* code */
      if (A[j] < A[minj]){
        minj=j;
      }


    }
  if(A[i]!=A[minj]){
    v=A[i];
    A[i]=A[minj];
    A[minj]=v;
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

